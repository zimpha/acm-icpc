#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 300000 + 10, SIZE = MAXN * 50;

struct Node {
  Node *ch[2];
  int sz;
} pool[SIZE], *rt[MAXN], *cnt, *null;

LL light[MAXN];
int n, m, a, b;

Node *newNode() {
  cnt->ch[0] = cnt->ch[1] = null;
  cnt->sz = 0; return cnt ++;
}

Node* ins(Node *o, LL x, int i = 0) {
  Node *p = newNode(); *p = *o;
  if (i == n) {p->sz ++; return p;}
  int c = x >> i & 1;
  p->ch[c] = ins(o->ch[c], x, i + 1);
  return p;
}

int ask(Node *o, LL x) {
  Node *p = o;
  for (int i = 0; i < n; ++ i) {
    int c = x >> i & 1;
    p = p->ch[!c];
  }
  return p->sz;
}

void init() {
  cnt = pool; null = newNode();
  null->ch[0] = null->ch[1] = null;
}

int main() {
  for (int cas(1); scanf("%d%d%d%d", &n, &m, &a, &b) == 4; ++ cas) {
    LL ret(0);
    init(); light[0] = 0;
    rt[0] = ins(null, 0);
    for (int i = 1; i <= m; ++ i) {
      char s[100]; scanf("%s", s);
      light[i] = 0;
      for (int j = 0; j < n; ++ j) {
        light[i] |= LL(s[j] - '0') << j;
      }
      Node *l = (i - b - 1 >= 0) ? rt[i - b - 1] : null;
      Node *r = (i - a >= 0) ? rt[i - a] : null;
      light[i] ^= light[i - 1];
      ret += ask(r, light[i]) - ask(l, light[i]);
      rt[i] = ins(rt[i - 1], light[i]);
    }
    printf("Case %d: %lld\n", cas, ret);
  }
  return 0;
}
