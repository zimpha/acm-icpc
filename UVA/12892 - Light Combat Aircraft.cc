#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 10000 + 10;

vector<int> G[MAXN];
int sz[MAXN], n;
LL dp[MAXN];

void dfs(int u) {
  dp[u] = 0; sz[u] = 1;
  for (auto &v: G[u]) {
    dfs(v);
    dp[u] += (LL)sz[u] * sz[v];
    sz[u] += sz[v];
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i) G[i].clear();
    for (int i = 1; i <= n; ++ i) {
      int x; scanf("%d", &x);
      G[x].push_back(i);
    }
    dfs(0);
    printf("Forest#%d:", cas);
    for (int i = 1; i <= n; ++ i) printf(" %lld", dp[i]);
    puts("");
  }
  return 0;
}

