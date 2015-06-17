#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
vector<int> G[MAXN];
int father[MAXN][20], dep[MAXN];
int n, q;

void bfs() {
  queue<int> Q; Q.push(1);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    for (auto &v: G[u]) {
      dep[v] = dep[u] + 1;
      father[v][0] = u;
      Q.push(v);
    }
  }
}

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
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; ++ i) {
    int p; scanf("%d", &p);
    G[p].push_back(i);
  }
  bfs();
  LCA::build();
  while (q --) {
    int u, v; scanf("%d%d", &u, &v);
    int f = LCA::ask(u, v);
    if (u == v) printf("%d %d\n", dep[u] + 1, dep[v] + 1);
    else if (f == u) {
      printf("%d %d\n", dep[u] + 1, dep[v] - dep[f]);
    }
    else if (f == v) {
      printf("%d %d\n", dep[u] - dep[f], dep[v] + 1);
    }
    else {
      printf("%d %d\n", dep[u] + 1, dep[v] - dep[f]);
    }
  }
  return 0;
}