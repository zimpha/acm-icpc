#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10, MAXM = 100000 + 10;

struct Edge {
  int u, v, w;
  bool operator < (const Edge &rhs) const {
    return w < rhs.w;
  }
} E[MAXM];
int g[MAXN][MAXN], dsu[MAXN], mk[MAXN];
int n, m, p;

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  while (scanf("%d%d%d", &n, &m, &p) == 3) {
    for (int i = 1; i <= n; ++ i) {
      dsu[i] = i; mk[i] = 0;
      for (int j = 1; j <= n; ++ j) g[i][j] = 0;
    }
    for (int i = 0; i < p; ++ i) {
      int x; scanf("%d", &x);
      mk[x] = 1;
    }
    for (int i = 0; i < m; ++ i) {
      scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
      g[E[i].u][E[i].v] = E[i].w;
      g[E[i].v][E[i].u] = E[i].w;
    }
    if (n == 1) {puts("0"); continue;}
    else if (n == 2) {
      if (m) printf("%d\n", E[0].w);
      else puts("impossible");
      continue;
    }
    sort(E, E + m);
    int add(0), ret(0);
    for (int i = 0; i < m; ++ i) {
      if (mk[E[i].u] || mk[E[i].v]) continue;
      int u = get(E[i].u), v = get(E[i].v);
      if (u == v) continue;
      dsu[u] = v; ++ add; ret += E[i].w;
    }
    if (add + 1 != n - p) {puts("impossible"); continue;}
    bool flag(true);
    for (int i = 1; i <= n; ++ i) if (mk[i]) {
      int mx(1e9);
      for (int j = 1; j <= n; ++ j) {
        if (!mk[j] && g[i][j]) mx = min(mx, g[i][j]);
      }
      if (mx == 1e9) {flag = false; break;}
      ret += mx;
    }
    if (flag) printf("%d\n", ret);
    else puts("impossible");
  }
  return 0;
}

