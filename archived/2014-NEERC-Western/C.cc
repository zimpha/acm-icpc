#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Node {
  int len, idx;
  Node() {}
  Node(int a, int b): len(a), idx(b) {}
};

const int MAXN = 100000 + 10;
vector<int> G[MAXN];

Node down[MAXN][2], best[MAXN][2];
int n;

void dfs1(int u, int f = -1) {
  down[u][0] = Node(0, u);
  down[u][1] = Node(0, 0);
  for (auto &v : G[u]) if (v != f) {
    dfs1(v, u);
    if (down[v][0].len + 1 > down[u][1].len) {
      down[u][1] = down[v][0];
      ++ down[u][1].len;
      if (down[u][1].len > down[u][0].len) swap(down[u][0], down[u][1]);
    }
  }
}

void dfs2(int u, int f = 0) {
  best[u][0] = down[u][0]; best[u][1] = down[u][1];
  if (f != 0) {
    for (int i = 0; i < 2; ++ i) {
      if (best[f][i].idx != down[u][0].idx) {
        if (best[f][i].len + 1 > best[u][1].len) {
          best[u][1] = best[f][i];
          ++ best[u][1].len;
        }
        if (best[u][1].len > best[u][0].len) {
          swap(best[u][0], best[u][1]);
        }
        break;
      }
    }
  }
  for (auto &v : G[u]) if (v != f) {
    dfs2(v, u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs1(1); dfs2(1);
  for (int i = 1; i <= n; ++ i) {
    if (i > 1) putchar(' ');
    printf("%d", best[i][0].len);
  }
  puts("");
  return 0;
}