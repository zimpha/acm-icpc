#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 100;
vector<PII> G[MAXN];
flt dp[MAXN][MAXN], ret;
int n, k;

void solve(int u, int f = -1, LL d = 0) {
  ret += d * dp[k][u];
  for (auto &x: G[u]) if (x.first != f) {
    solve(x.first, u, x.second + d);
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      -- u, -- v;
      G[u].push_back(PII(v, w));
      G[v].push_back(PII(u, w));
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < k; ++ i) {
      for (int u = 0; u < n; ++ u) {
        for (auto &x: G[u]) {
          dp[i + 1][x.first] += dp[i][u] / G[u].size();
        }
      }
    }
    ret = 0; solve(0);
    printf("%.10f\n", ret);
  }
  return 0;
}

