#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
const LL inf = 1ll << 60;
vector<PII> G[MAXN];
LL dis[MAXN];
int vis[MAXN], n, m; 

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++ i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(PII(v, w));
  }
  for (int i = 1; i <= n; ++ i) dis[i] = inf;
  queue<int> Q; Q.push(1); vis[1] = true; dis[1] = 0;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); vis[u] = false;
    for (auto &x : G[u]) {
      int v = x.first, w = x.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v]) vis[v] = true, Q.push(v);
      }
    }
  }
  if (dis[n] == inf) puts("Infinity");
  else printf("%lld\n", dis[n]);
  return 0;
}