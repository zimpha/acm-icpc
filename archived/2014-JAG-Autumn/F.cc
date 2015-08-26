#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXM = 200000 + 10, MAXN = 1000 + 10, inf = 1e9;
namespace NF {
  struct Edge {
    int v, c, f, nx;
    Edge() {}
    Edge(int v, int c, int f, int nx):
      v(v), c(c), f(f), nx(nx) {}
  } E[MAXM];
  int G[MAXN], lev[MAXN], cur[MAXN];
  int sz, N;
  void init(int n) {
    N = n; sz = 0;
    memset(G, -1, sizeof(G));
  }
  void link(int u, int v, int c) {
    E[sz] = Edge(v, c, 0, G[u]); G[u] = sz ++;
    E[sz] = Edge(u, 0, 0, G[v]); G[v] = sz ++;
  }
  bool bfs(int S, int T) {
    static int Q[MAXN];
    for (int i = 0; i < N; ++ i) lev[i] = -1;
    Q[0] = S; lev[S] = 0;
    for (int h = 0, t = 1; h < t; ++ h) {
      int u = Q[h], v;
      for (int now = G[u]; ~now; now = E[now].nx) {
        if (lev[v = E[now].v] == -1 && E[now].c > E[now].f) {
          lev[v] = lev[u] + 1; Q[t ++] = v;
        }
      }
    }
    return lev[T] != -1;
  }
  int dfs(int u, int T, int low) {
    if (u == T) return low;
    int ret = 0, tmp, v;
    for (int &now = cur[u]; ~now && ret < low; now = E[now].nx) {
      if (lev[v = E[now].v] == lev[u] + 1 && E[now].c > E[now].f) {
        tmp = dfs(v, T, min(low - ret, E[now].c - E[now].f));
        ret += tmp; E[now].f += tmp; E[now ^ 1].f -= tmp;
      }
    }
    if (!ret) lev[u] = -1; return ret;
  }
  int dinic(int S, int T) {
    int ret = 0;
    while (bfs(S, T)) {
      memcpy(cur, G, sizeof(G[0]) * N);
      ret += dfs(S, T, inf);
    }
    return ret;
  }
  static bool mark[MAXN];
  int solve(int S, int T) {
    bfs(S, T); int ret = 0;
    memset(mark, 0, sizeof(mark));
    queue<int> Q; Q.push(T); mark[T] = true;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (int now = G[u]; ~now; now = E[now].nx) {
        int v = E[now].v;
        if (E[now ^ 1].c > E[now ^ 1].f) {
          if (!mark[v]) mark[v] = true, Q.push(v);
        }
        else ret += (lev[v] != -1 && E[now].c > 0);
      }
    }
    return ret;
  }
}

int main() {
  int n, m, s, t; 
  while (scanf("%d%d%d%d", &n, &m, &s, &t) == 4 && n) {
    NF::init(n); -- s; -- t;
    for (int i = 0, u, v; i < m; ++ i) {
      scanf("%d%d", &u, &v); -- u, -- v;
      NF::link(u, v, 1);
    }
    int maxflow = NF::dinic(s, t);
    int ret = NF::solve(s, t);
    if (ret != 0) maxflow ++;
    printf("%d %d\n", maxflow, ret);
  }
  return 0;
}