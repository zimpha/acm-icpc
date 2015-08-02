#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;

vector<int> G[MAXN];
int fa[MAXN][18], st[MAXN], ed[MAXN], dep[MAXN];
int N, sz;

namespace LCA {
  const static int POW = 17;
  void build(int n) {
    for (int i=1;(1<<i)<=n;++i) {
      for (int j=1;j<=n;++j) if (fa[j][i-1]) {
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

bool is_anc(int u, int v) {
  return st[u] <= st[v] && ed[u] >= ed[v];
}

void dfs(int u, int f = -1) {
  st[u] = sz ++;
  for (auto &v: G[u]) if (v != f) {
    dep[v] = dep[u] + 1;
    fa[v][0] = u;
    dfs(v, u);
  }
  ed[u] = sz ++;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++ i) {
      memset(fa[i], 0, sizeof(fa[i]));
      G[i].clear();
    }
    for (int i = 1; i < N; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    sz = 0; dfs(1);
    LCA::build(N);
    int Q; scanf("%d", &Q);
    while (Q --) {
      static int nd[MAXN], vs[MAXN];
      int K, tot(0); scanf("%d", &K);
      int da(-1), la(-1);
      int db(-1), lb(-1);
      for (int i = 0; i < K; ++ i) {
        scanf("%d", nd + i); vs[i] = 0;
        if (da == -1 || dep[da] < dep[nd[i]]) da = nd[i];
      }
      for (int i = 0; i < K; ++ i) if (!vs[i]) {
        if (is_anc(nd[i], da)) {
          vs[i] = 1; ++ tot;
          if (la == -1 || dep[la] > dep[nd[i]]) la = nd[i];
        }
      }
      for (int i = 0; i < K; ++ i) if (!vs[i]) {
        if (db == -1 || dep[db] < dep[nd[i]]) db = nd[i];
      }
      if (db == -1) {puts("Yes"); continue;}

      for (int i = 0; i < K; ++ i) if (!vs[i]) {
        if (is_anc(nd[i], db)) {
          vs[i] = 1; ++ tot;
          if (lb == -1 || dep[lb] > dep[nd[i]]) lb = nd[i];
        }
      }
      if (tot != K) {puts("No"); continue;}
      int f = LCA::ask(da, db);
      if (is_anc(f, la) && is_anc(f, lb)) puts("Yes");
      else puts("No");
    }
  }
  return 0;
}