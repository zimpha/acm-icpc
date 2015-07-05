#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int MAXN = 200, MAXS = 1 << 15;
LL dp[MAXN][MAXS], tmp[MAXS];
int n, m, s;

int main() {
  scanf("%d%d", &n, &m);
  if (n < m) swap(n, m);
  int s = 1 << (m + 1);
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      int u = (i - 1) * m + j, v = u - 1;
      for (int msk = 0; msk < s; ++ msk) if (dp[v][msk]) {
        dp[v][msk] %= MOD;
        int a = j - 1, x = (msk >> a) & 1, y = (msk >> j) & 1;

        if (x == 1 && y == 0) {
          dp[u][msk] += dp[v][msk];
          if (j != m) dp[u][msk ^ (1 << a) ^ (1 << j)] += dp[v][msk];
        }
        if (x == 1 && y == 1) {
          dp[u][msk ^ (1 << a) ^ (1 << j)] += dp[v][msk];
        }
        if (x == 0 && y == 1) {
          dp[u][msk ^ (1 << a) ^ (1 << j)] += dp[v][msk];
          if (j != m) dp[u][msk] += dp[v][msk];
        }
        if (x == 0 && y == 0 && j != m) {
          dp[u][msk ^ (1 << a) ^ (1 << j)] += dp[v][msk];
        }
      }
      if (j == m) {
        memcpy(tmp, dp[u], sizeof(tmp[0]) * s);
        memset(dp[u], 0, sizeof(tmp[0]) * s);
        for (int msk = 0; msk < s; ++ msk) if (tmp[msk]) {
          int new_msk = msk ^ (msk >> m << m);
          new_msk <<= 1; new_msk ^= (msk >> m);
          dp[u][new_msk] += tmp[msk];
        }
      }
    }
  }
  printf("%lld\n", dp[n * m][0] % MOD);
  return 0;
}

