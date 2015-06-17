#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 4000 + 10;
const int MOD = 1e9;

int C[MAXN][MAXN], dp[MAXN][MAXN], sum[MAXN];

int main() {
  for (int i = 0; i < MAXN; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++ j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N, M; scanf("%d%d", &N, &M);
    for (int i = 0; i <= M; ++ i) {
      sum[i] = C[i + M - 1][M - 1];
      dp[0][i] = 1;
    }
    for (int i = 1; i <= N; ++ i) {
      for (int j = 0; j <= M; ++ j) {
        dp[i][j] = (LL)dp[i - 1][j] * sum[j] % MOD;
      }
      for (int j = 1; j <= M; ++ j) {
        dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
      }
    }
    printf("%d\n", dp[N][M]);
  }
  return 0;
}
