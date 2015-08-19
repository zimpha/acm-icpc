#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<PII> G[MAXN];
LL dis[MAXN], sz[MAXN];
int n;

void dfs1(int u, int f = -1) {
  sz[u] = 1; dis[u] = 0;
  for (auto &x: G[u]) {
    int v = x.first; if (v == f) continue;
    dfs1(v, u);
    sz[u] += sz[v];
    dis[u] += dis[v] + sz[v] * x.second;
  }
}

void dfs2(int u, int f = -1) {
  for (auto &x: G[u]) {
    int v = x.first; if (v == f) continue;
    dis[v] = dis[u] + (n - sz[v]) * x.second - sz[v] * x.second;
    dfs2(v, u);
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      -- u; -- v;
      G[u].push_back(PII(v, w));
      G[v].push_back(PII(u, w));
    }
    dfs1(0);
    dfs2(0);
    for (int i = 0; i < n; ++ i) printf("%lld\n", dis[i]);
  }
  return 0;
}

