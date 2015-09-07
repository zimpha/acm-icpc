#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int has[MAXN], sz[MAXN], N, F;
vector<PII> G[MAXN];

void dfs(int u, int f) {
  sz[u] = has[u];
  for (auto &x : G[u]) if (x.first != f) {
    dfs(x.first, u); sz[u] += sz[x.first];
  }
}

PII solve(int u, int f) {
  PII ret(0, 0);
  for (auto &x : G[u]) if (x.first != f) {
    int v = x.first, w = x.second;
    if (sz[v] == 0) continue;
    PII tmp = solve(v, u);
    ret.first = max(ret.first, tmp.first + w);
    ret.second += tmp.second + w;
  }
  return ret;
}

int main() {
  while (scanf("%d%d", &N, &F) == 2) {
    for (int i = 0; i < N; ++ i) G[i].clear(), has[i] = false;
    for (int i = 1; i < N; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      G[-- u].push_back(PII(-- v, w));
      G[v].push_back(PII(u, w));
    }
    for (int i = 0; i < F; ++ i) {
      int u; scanf("%d", &u);
      has[u - 1] = true;
    }
    dfs(0, -1);
    PII ret = solve(0, -1);
    printf("%d\n", ret.second - ret.first);
  }
  return 0;
}
