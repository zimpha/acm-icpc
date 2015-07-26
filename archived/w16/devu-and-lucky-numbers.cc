#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100 + 10, MOD = 1e9 + 7;

LL dp[MAXN][MAXN][MAXN], cnt[MAXN][MAXN][MAXN];
int x, y, z;

int main() {
  scanf("%d%d%d", &x, &y, &z);
  LL ret(0); cnt[0][0][0] = 1;
  for (int i = 0; i <= x; ++ i) {
    for (int j = 0; j <= y; ++ j) {
      for (int k = 0; k <= z; ++ k) {
        dp[i][j][k] %= MOD; ret += dp[i][j][k]; cnt[i][j][k] %= MOD;
        cnt[i + 1][j][k] += cnt[i][j][k];
        cnt[i][j + 1][k] += cnt[i][j][k];
        cnt[i][j][k + 1] += cnt[i][j][k];
        dp[i + 1][j][k] += (dp[i][j][k] * 10 + 4 * cnt[i][j][k]) % MOD;
        dp[i][j + 1][k] += (dp[i][j][k] * 10 + 5 * cnt[i][j][k]) % MOD;
        dp[i][j][k + 1] += (dp[i][j][k] * 10 + 6 * cnt[i][j][k]) % MOD;
      }
    }
  }
  ret %= MOD;
  printf("%lld\n", ret);
  return 0;
}

