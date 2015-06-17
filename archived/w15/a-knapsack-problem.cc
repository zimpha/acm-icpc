#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10, inf = 1e9;
int ct[MAXN], vl[MAXN], n, R, best;
vector<int> G[MAXN];

namespace TKP {
  int sz[MAXN], vis[MAXN], P[MAXN][MAXN];
  int rt, tot, mins, cnt;
  int rmin, rpath;
  void init(int n) {
    for (int i = 0; i < n; ++ i) vis[i] = false;
  }
  void getCenter(int u, int f = -1) {
    sz[u] = 1; int mx = 0; rmin = min(rmin, ct[u]);
    for (auto &v: G[u]) if (v != f && !vis[v]) {
      getCenter(v, u); 
      sz[u] += sz[v]; 
      mx = max(mx, sz[v]);
    }
    mx = max(mx, tot - sz[u]);
    if (mx < mins) mins = mx, rt = u;
  }
  void dfs(int u, int f, int rpath) {
    rpath += ct[u]; sz[u] = 1;
    for (int i = rmin; i < rpath && i <= R; ++ i) P[u][i] = -inf;
    for (int i = rpath; i <= R; ++ i) {
      P[u][i] = P[f][i - ct[u]] + vl[u];
    }
    for (auto &v: G[u]) if (v != f && !vis[v]) {
      dfs(v, u, rpath); sz[u] += sz[v];
    }
    rpath -= ct[u];
    for (int i = rmin; i <= R; ++ i) {
      if (P[f][i] < P[u][i]) P[f][i] = P[u][i];
    }
  }
  void solve(int u, int _tot) {
    mins = _tot * 2, tot = _tot;
    rmin = ct[u];
    getCenter(u);
    u = rt; 
    vis[rt] = true;
    for (int i = rmin; i < ct[u]; ++ i) P[u][i] = -inf;
    for (int i = ct[u]; i <= R; ++ i) P[u][i] = vl[u];
    for (auto &v: G[u]) if (!vis[v]) {
      dfs(v, u, ct[u]);
    }
    best = max(best, P[u][R]);
    for (auto &v: G[u]) if (!vis[v]) {
      solve(v, sz[v]);
    } 
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &R);
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 0; i < n; ++ i) scanf("%d", ct + i);
    for (int i = 0; i < n; ++ i) scanf("%d", vl + i);
    for (int i = 1; i < n; ++ i) {
      int u, v; scanf("%d%d", &u, &v); -- u, -- v;
      G[u].push_back(v); G[v].push_back(u);
    }
    best = 0;
    TKP::init(n);
    TKP::solve(0, n);
    printf("%d\n", best);
  }
  return 0;
}