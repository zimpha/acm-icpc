#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

vector<int> G[MAXN], Gr[MAXN], dom[MAXN];
int semi[MAXN], dsu[MAXN], idom[MAXN], best[MAXN];
int dfn[MAXN], pre[MAXN], id[MAXN];
int n, m, sz;

int get(int x) {
  if (x == dsu[x]) return x;
  int y = get(dsu[x]);
  if (semi[best[x]] > semi[best[dsu[x]]]) best[x] = best[dsu[x]];
  return dsu[x] = y;
}
void dfs(int u) {
  dfn[u] = ++ sz; id[sz] = u;
  for (auto &v: G[u]) if (!dfn[v]) {
    dfs(v); pre[dfn[v]] = dfn[u];
  }
}
void tarjan() {
  for (int j = sz, u; u = id[j], j >= 2; -- j) {
    for (auto &x: Gr[u]) {
      int v = dfn[x]; if (!v) continue;
      get(v);
      if (semi[best[v]] < semi[j]) semi[j] = semi[best[v]];
    }
    dom[semi[j]].push_back(j);
    int x = dsu[j] = pre[j];
    for (auto &z: dom[x]) {
      get(z);
      if (semi[best[z]] < x) idom[z] = best[z];
      else idom[z] = x;
    }
    dom[x].clear();
  }
  for (int i = 2; i <= sz; ++ i) {
    if (semi[i] != idom[i]) idom[i] = idom[idom[i]];
    dom[idom[i]].push_back(i);
  }
}
int cnt[MAXN];
void calc(int u) {
  cnt[u] = 1;
  for (auto &v: dom[u]) {
    calc(v); cnt[u] += cnt[v];
  }
}
int main() {
  scanf("%d%d", &n, &m); sz = 0;
  for (int i = 1; i <= n; ++ i) {
    dfn[i] = cnt[i] = 0;
    dsu[i] = best[i] = semi[i] = i;
  }
  for (int i = 1; i <= m; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    G[u].push_back(v);
    Gr[v].push_back(u);
  }
  dfs(1);
  tarjan();
  calc(1);
  LL ret = (LL)cnt[1] * (cnt[1] - 1) / 2;
  for (auto &v: dom[1]) {
    ret -= (LL)cnt[v] * (cnt[v] - 1) / 2;
  }
  printf("%lld\n", ret);
  return 0;
}