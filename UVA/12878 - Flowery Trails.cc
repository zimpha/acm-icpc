#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10, inf = 1e9;

vector<PII> G[MAXN];
int d1[MAXN], d2[MAXN], n, m;
int vis[MAXN];

void spfa(int s, int d[]) {
  for (int i = 0; i < n; ++ i) {
    vis[i] = 0; d[i] = inf;
  }
  queue<int> Q; Q.push(s);
  vis[s] = 1; d[s] = 0;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); vis[u] = 0;
    for (auto &x: G[u]) {
      int v = x.first, w = x.second;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        if (!vis[v]) vis[v] = 1, Q.push(v);
      }
    }
  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 0; i < m; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      G[u].push_back(PII(v, w));
      G[v].push_back(PII(u, w));
    }
    spfa(0, d1); spfa(n - 1, d2);
    int ret(0);
    for (int u = 0; u < n; ++ u) {
      for (auto &x: G[u]) {
        if (d1[u] + d2[x.first] + x.second == d2[0]) {
          ret += x.second;
        }
      }
    }
    printf("%d\n", ret * 2);
  }
  return 0;
}

