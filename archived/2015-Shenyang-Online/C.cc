#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;

struct Edge {
  int v, nx;
} E[MAXN];

int a[MAXN], b[MAXN], G[MAXN];
int sz[MAXN], st[MAXN], ed[MAXN], index;
int n, m, ecnt;

void addedge(int u, int v) {
  E[ecnt].v = v; E[ecnt].nx = G[u]; G[u] = ecnt ++;
  E[ecnt].v = u; E[ecnt].nx = G[v]; G[v] = ecnt ++;
}

struct FastIO {
  static const int S = 131072;
  int wpos; char wbuf[S];
  FastIO() : wpos(0) {}
  inline int xchar() {
    static char buf[S];
    static int len = 0, pos = 0;
    if (pos == len)
      pos = 0, len = fread(buf, 1, S, stdin);
    if (pos == len) return -1;
    return buf[pos ++];
  }
  inline int xint() {
    int c = xchar(), x = 0;
    while (c <= 32) c = xchar();
    for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
    return x;
  }
} io;


void dfs(int u, int f = -1) {
  st[u] = index ++;
  for (int it = G[u]; ~it; it = E[it].nx) {
    int v = E[it].v; if (v == f) continue;
    dfs(v, u); sz[u] += sz[v];
  }
  ed[u] = index;
}

struct Node {
  int l, r, id;
  bool operator < (const Node &rhs) const {
    return l > rhs.l;
  }
} ql[MAXN], seq[MAXN];

int u[MAXN];
void add(int x) {
  for (; x <= n; x += ~x & x + 1) u[x] ++;
}
int get(int x) {
  int r(0);
  for (; x >= 0; x -= ~x & x + 1) r += u[x];
  return r;
}

int main() {
  int T = io.xint();
  for (int cas = 1; cas <= T; ++ cas) {
    n = io.xint(); m = io.xint();
    m -= n - 1; index = 0; ecnt = 0;
    for (int i = 1; i <= n; ++ i) {
      G[i] = -1; sz[i] = 0;
    }
    for (int i = 0; i <= n; ++ i) u[i] = 0;
    for (int i = 1; i < n; ++ i) {
      int u, v; 
      u = io.xint(); v = io.xint();
      addedge(u, v);
    }
    for (int i = 0; i < m; ++ i) {
      a[i] = io.xint(); b[i] = io.xint();
      sz[a[i]] ++; sz[b[i]] ++;
    }
    dfs(1);
    for (int i = 2; i <= n; ++ i) {
      ql[i].l = st[i];
      ql[i].r = ed[i] - 1;
      ql[i].id = i;
    }
    for (int i = 0; i < m; ++ i) {
      seq[i].l = st[a[i]];
      seq[i].r = st[b[i]];
      if (seq[i].l > seq[i].r) swap(seq[i].l, seq[i].r);
    }
    sort(ql, ql + n - 1);
    sort(seq, seq + m);
    for (int i = 0, j(0); i < n - 1; ++ i) {
      while (j < m && seq[j].l >= ql[i].l) {
        add(seq[j].r); ++ j;
      }
      sz[ql[i].id] -= (get(ql[i].r) - get(ql[i].l - 1)) * 2;
    }
    int ret(m);
    for (int i = 2; i <= n; ++ i) {
      ret = min(ret, sz[i]);
    }
    printf("Case #%d: %d\n", cas, ret + 1);
  }
  return 0;
}