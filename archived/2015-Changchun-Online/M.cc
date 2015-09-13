#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 50000 + 10;

vector<int> G[MAXN];
LL D[MAXN], sz[MAXN], dep[MAXN];
int fa[MAXN][20];
int n, q;

void dfs(int u, int f = -1) {
  sz[u] = 1; D[u] = 0;
  for (size_t i = 0; i < G[u].size(); ++ i) {
    int v = G[u][i]; if (v == f) continue;
    dep[v] = dep[u] + 1; fa[v][0] = u;
    dfs(v, u); sz[u] += sz[v];
    D[u] += D[v] + sz[v];
  }
}

void dfs2(int u, int f = -1) {
  for (size_t i = 0; i < G[u].size(); ++ i) {
    int v = G[u][i]; if (v == f) continue;
    D[v] = D[u] + n - sz[v] * 2;
    dfs2(v, u);
  }
}

namespace LCA {
  const static int POW = 15;
  void build(int n) {
    for (int i=1;(1<<i)<=n;++i) {
      for (int j=0;j<n;++j) if (~fa[j][i-1]) {
        fa[j][i]=fa[fa[j][i-1]][i-1];
      }
    }
  }
  int up(int u, int d) {
    for (int i=0;d;++i,d>>=1) if (d&1) u=fa[u][i];
    return u;
  }
  int ask(int u, int v) {
    if (dep[u]<dep[v]) swap(u,v);
    u=up(u,dep[u]-dep[v]);
    for (int i=POW;i>=0;--i) {
      if (fa[u][i]==fa[v][i]) continue;
      u=fa[u][i]; v=fa[v][i];
    }
    if (u!=v) u=fa[u][0]; return u;
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    if (_) puts("");
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      G[i].clear();
      memset(fa[i], -1, sizeof(fa[i]));
    }
    for (int i = 1; i < n; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(0); dfs2(0);
    LCA::build(n);
    int q; scanf("%d", &q);
    while (q --) {
      int p, x; scanf("%d%d", &p, &x);
      LL ret(0);
      for (int i = 0, y; i < p; ++ i) {
        scanf("%d", &y);
        int f = LCA::ask(x, y);
        int d = dep[x] + dep[y] - 2 * dep[f];
        ret += (LL)(n - 1) * d + D[y] - D[x];
        x = y;
      }
      printf("%lld.0000\n", ret);
    }
  }
  return 0;
}

