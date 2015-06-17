#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 20000 + 10, inf = 1e9;
vector<PII> G[MAXN], E[MAXN];
int f[MAXN], g[MAXN], deg[MAXN];
int N, M, K;

void spfa(int d[]) {
  queue<int> Q;
  for (int i = 1; i <= N; ++ i) {
    if (deg[i] == 1) Q.push(i), g[i] = 1, d[i] = 0;
    else g[i] = 0, d[i] = inf;
  }
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); g[u] = 0;
    for (auto &x: G[u]) {
      int v = x.first, w = x.second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        if (!g[v]) Q.push(v), g[v] = 1;
      }
    }
  }
}
void spfa2() {
  static bool vis[MAXN][2];
  queue<PII> Q;
  for (int i = 1; i <= N; ++ i) {
    Q.push(PII(i, 0)); 
    vis[i][0] = 1; g[i] = inf;
  }
  while (!Q.empty()) {
    int u = Q.front().first, o = Q.front().second;
    vis[u][o] = 0; Q.pop();
    if (o == 1) {
      for (auto &x: G[u]) {
        int v = x.first, w = x.second;
        if (g[v] > g[u] + w) {
          g[v] = g[u] + w;
          if (!vis[v][1]) vis[v][1] = 1, Q.push(PII(v, 1));
        }
      }
    }
    else {
      for (auto &x: E[u]) {
        int v = x.first, w = x.second;
        if (g[v] > f[u] + w) {
          g[v] = f[u] + w;
          if (!vis[v][1]) vis[v][1] = 1, Q.push(PII(v, 1));
        }
      }
    }
  }
  for (int i = 1; i <= N; ++ i) f[i] = min(f[i], g[i]);
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i < N; ++ i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(PII(v, w)); deg[v] ++;
    G[v].push_back(PII(u, w)); deg[u] ++;
  }
  for (int i = 0; i < M; ++ i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    E[u].push_back(PII(v, w));
    E[v].push_back(PII(u, w));
  }
  spfa(f);
  for (int _ = 0; _ < K; ++ _) spfa2();
  if (N == 1) f[1] = 0;
  for (int i = 1; i <= N; ++ i) printf("%d\n", f[i]);
  return 0;
}
