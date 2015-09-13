#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
vector<int> G[MAXN];
int p[MAXN], vs[MAXN];
int deg[MAXN], n, m;
int sz; LL tot;

void dfs(int u) {
  vs[u] = 1; sz ++; tot += p[u];
  for (size_t i = 0; i < G[u].size(); ++ i) {
    int v = G[u][i];
    if (!vs[v]) dfs(v);
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", p + i);
      vs[i] = 0; deg[i] = 0;
      G[i].clear();
    }
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      u --; v --; deg[u] ++; deg[v] ++;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    queue<int> Q;
    for (int i = 0; i < n; ++ i) {
      if (deg[i] <= 1) {
        Q.push(i);
        vs[i] = 1;
      }
    }
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      for (size_t i = 0; i < G[u].size(); ++ i) {
        int v = G[u][i]; if (vs[v]) continue;
        if (-- deg[v] == 1) {
          Q.push(v);
          vs[v] = 1;
        }
      }
    }
    LL ret(0);
    for (int i = 0; i < n; ++ i) if (!vs[i]) {
      sz = 0; tot = 0;
      dfs(i);
      if (sz & 1) ret += tot;
    }
    printf("%lld\n", ret);
  }
  return 0;
}

