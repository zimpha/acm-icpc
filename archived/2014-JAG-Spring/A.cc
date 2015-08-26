#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<int> G[MAXN];
vector<int> Q;
int father[MAXN][20];
int n, dep[MAXN];

namespace LCA {
  const int POW = 19;
  void build() {
    for (int i = 1; (1 << i) <= n; ++ i) {
      for (int j = 1; j <= n; ++ j) {
        if (father[j][i - 1] == 0) continue;
        father[j][i] = father[father[j][i - 1]][i - 1];
      }
    }
  }
  int up(int u, int d) {
    for (int i = 0; d; ++ i, d >>= 1) {
      if (d & 1) u = father[u][i];
    }
    return u;
  }
  int ask(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    u = up(u, dep[u] - dep[v]);
    for (int i = POW; i >= 0; -- i) {
      if (father[u][i] == father[v][i]) continue;
      u = father[u][i]; v = father[v][i];
    }
    if (u != v) u = father[u][0];
    return u;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++ i) {
    int p; scanf("%d", &p);
    G[p].push_back(i);
  }
  Q.push_back(1); dep[1] = 0;
  for (size_t i = 0; i < Q.size(); ++ i) {
    int u = Q[i];
    for (auto &v : G[u]) {
      Q.push_back(v); 
      dep[v] = dep[u] + 1;
      father[v][0] = u;
    }
  }
  LCA::build();
  LL ret = 0;
  for (size_t i = 1; i < Q.size(); ++ i) {
    int u = LCA::ask(Q[i - 1], Q[i]);
    ret += dep[Q[i - 1]] + dep[Q[i]] - 2 * dep[u];
  }
  printf("%lld\n", ret);
  return 0;
}