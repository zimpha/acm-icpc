#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &rhs) const {
    return w < rhs.w;
  }
} E[MAXN];

struct Node {
  int x, id;
  bool operator < (Node &rhs) const {
    return x < rhs.x;
  }
} ql[MAXN];

int dsu[MAXN], sz[MAXN];
int ret[MAXN];
int n, m, q;

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m, q; scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; ++ i) {
      dsu[i] = i; sz[i] = 1;
    }
    for (int i = 0; i < m; ++ i) {
      scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
      -- E[i].u; -- E[i].v;
    }
    sort(E, E + m);
    for (int i = 0; i < q; ++ i) {
      scanf("%d", &ql[i].x);
      ql[i].id = i;
    }
    sort(ql, ql + q);
    int tot(0);
    for (int i = 0, j(0); i < q; ++ i) {
      for (;j < m && E[j].w <= ql[i].x; ++ j) {
        int u = get(E[j].u), v = get(E[j].v);
        if (u != v) {
          tot += sz[u] * sz[v] * 2;
          dsu[u] = v; sz[v] += sz[u];
        }
      }
      ret[ql[i].id] = tot;
    }
    for (int i = 0; i < q; ++ i) {
      printf("%d\n", ret[i]);
    }
  }
  return 0;
}
