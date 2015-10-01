#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;

struct Edge {
  int v, nx;
} E[MAXN << 1];
int G[MAXN], deg[MAXN], vis[MAXN];
int n, m, d;

void dfs(int u) {
  deg[d ++] = u; vis[u] = 1;
  for (int it = G[u]; ~it; it = E[it].nx) {
    if (!vis[E[it].v]) dfs(E[it].v);
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &d);
  memset(G, -1, sizeof(G[0]) * n);
  for (int i = 0; i < m; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    deg[-- u] ++; deg[-- v] ++;
    E[i << 1] = {v, G[u]}; G[u] = i<<1;
    E[i<<1|1] = {u, G[v]}; G[v] = i<<1|1;
  }
  static int Q[MAXN], h(0), t(0);
  for (int i = 0; i < n; ++ i) if (deg[i] < d) {
    Q[t ++] = i; vis[i] = 1;
  }
  for (; h < t; ++ h) {
    int u = Q[h];
    for (int it = G[u]; ~it; it = E[it].nx) {
      int v = E[it].v; if (vis[v]) continue;
      if (-- deg[v] < d) vis[v] = 1, Q[t ++] = v;
    }
  }
  vector<int> ret;
  for (int i = 0; i < n; ++ i) if (!vis[i]) {
    d = 0; dfs(i);
    if (d > (int)ret.size()) {
      ret = vector<int>(deg, deg + d);
    }
  }
  if (ret.empty()) puts("NIE");
  else {
    sort(ret.begin(), ret.end());
    printf("%d\n", (int)ret.size());
    for (auto &x: ret) printf("%d ", x + 1);
    puts("");
  }
  return 0;
}

