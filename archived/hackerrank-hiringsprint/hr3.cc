#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<PII> G[MAXN];
LL dis[MAXN];
int vis[MAXN], n, m, s;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++ i) {
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    G[u].push_back(PII(v, w));
    G[v].push_back(PII(u, w));
  }
  for (int i = 1; i <= n; ++ i) dis[i] = 1ll<<60;
  queue<int> Q;
  scanf("%d", &s);
  for (int i = 0; i < s; ++ i) {
    int x; scanf("%d", &x);
    dis[x] = 0; vis[x] = 1;
    Q.push(x);
  }
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); vis[u] = 0;
    for (auto &x: G[u]) {
      int v = x.first, w = x.second;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (!vis[v]) vis[v] = 1, Q.push(v);
      }
    }
  }
  for (int i = 1; i <= n; ++ i) printf("%lld\n", dis[i]);
  return 0;
}

