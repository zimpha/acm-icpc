#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<PII> G[MAXN];
LL f[MAXN], g[MAXN];
int sz[MAXN], n;

void dfs1(int u, int p = -1) {
  f[u] = 0; sz[u] = 1;
  for (auto &x: G[u]) {
    int v = x.first, w = x.second;
    if (v == p) continue;
    dfs1(v, u); sz[u] += sz[v];
    f[u] += f[v] + (LL)sz[v] * w;
  }
}

void dfs2(int u, int p = -1) {
  for (auto &x: G[u]) {
    int v = x.first, w = x.second;
    if (v == p) continue;
    g[v] = f[v] + g[u] - (f[v] + (LL)sz[v] * w) + LL(n - sz[v]) * w;
    dfs2(v, u);
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      G[u].push_back(PII(v, w));
      G[v].push_back(PII(u, w));
    }
    dfs1(1);
    g[1] = f[1];
    dfs2(1);
    for (int i = 1; i <= n; ++ i) printf("%lld\n", g[i]);
  }
  return 0;
}

