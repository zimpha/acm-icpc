#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100, SIZE = 2e7;

struct Node {
  Node *ch[2];
  int sz;
} pool[SIZE], *pt, *null;
Node *rt[MAXN][MAXN];

Node *newNode() {
  pt->ch[1] = pt->ch[0] = null;
  pt->sz = 0; return pt ++;
}

void ins(Node *rt, int n) {
  Node *p = rt; p->sz ++;
  for (int i = 30; i >= 0; -- i) {
    int o = (n >> i) & 1;
    if (p->ch[o] == null) p->ch[o] = newNode();
    p = p->ch[o];
    p->sz ++;
  }
}

int ask(Node *rt, int n) {
  int ret = 0; Node *p = rt;
  for (int i = 30; i >= 0; -- i) {
    int o = (n >> i) & 1;
    if (p->ch[o ^ 1]->sz) ret |= 1 << i, o ^= 1;
    p = p->ch[o];
  }
  return ret;
}

int mp[MAXN][MAXN], n;
bool fit(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs1(int x, int y, int d, int s) {
  if (!fit(x, y)) return;
  s ^= mp[x][y];
  if (d == 0) {
    ins(rt[x][y], s);
    return;
  }
  dfs1(x + 1, y, d - 1, s);
  dfs1(x, y + 1, d - 1, s);
}

int best;
void dfs2(int x, int y, int d, int s) {
  if (!fit(x, y)) return;
  s ^= mp[x][y];
  if (d == 0) {
    best = max(best, ask(rt[x][y], s ^ mp[x][y]));
    return;
  }
  dfs2(x - 1, y, d - 1, s);
  dfs2(x, y - 1, d - 1, s);
}

int main() {
  pt = pool; null = newNode();
  null->ch[0] = null->ch[1] = null;
  null->sz = 0; best = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      scanf("%d", &mp[i][j]);
      rt[i][j] = newNode();
    }
  }
  dfs1(0, 0, n - 1, 0);
  dfs2(n - 1, n - 1, n - 1, 0);
  printf("%d\n", best);
  return 0;
}