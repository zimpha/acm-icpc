#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double flt;
typedef pair<int, int> PII;
const int MAXN = 60, SIZE = 1000 + 10;

flt dp[MAXN][MAXN][MAXN], p;
flt Q[MAXN], f[SIZE][MAXN];
flt fac[MAXN];
int A, B, N;

flt C(int n, int m) {
  return fac[n] - fac[m] - fac[n - m];
}

flt calc(int i, int j, int k) {
  if (i < j - k) return 0;
  else return exp(C(N - i, k) + C(i, j - k) - C(N, j));
}

int main() {
  fac[0] = fac[1] = 0;
  for (int i = 2; i < MAXN; ++ i) fac[i] = fac[i - 1] + log(1.0 * i);
  scanf("%d%d%d%lf", &N, &A, &B, &p);
  memset(dp, 0, sizeof(dp)); dp[0][0][0] = 1;
  for (int i = 0; i < B; ++ i) {
    for (int j = 0; j <= N && j <= i; ++ j) {
      for (int k = 0; k <= j && k < N; ++ k) {
        if (dp[i][j][k] == 0) continue;
        dp[i + 1][j][k + 1] += dp[i][j][k] * p * (j - k) / (N - k);
        dp[i + 1][j][k] += dp[i][j][k] * (1.0 - p) * (j - k) / (N - k);
        if (j < N) {
          dp[i + 1][j + 1][k + 1] += dp[i][j][k] * p * (N - j) / (N - k);
          dp[i + 1][j + 1][k] += dp[i][j][k] * (1.0 - p) * (N - j) / (N - k);
        }
      }
    }
    if (dp[i][N][N] != 0) dp[i + 1][N][N] += dp[i][N][N];
  }
  for (int i = A; i <= B; ++ i) {
    for (int j = 0; j <= N; ++ j) {
      for (int k = 0; k <= j; ++ k) {
        Q[j] += dp[i][j][k];
      }
    }
  }
  for (int j = 0; j <= N; ++ j) {
    Q[j] /= flt(B - A + 1);
  }
  int L = 1000; f[0][0] = 1;
  for (int t = 0; t < L; ++ t) {
    for (int i = 0; i <= N; ++ i) {
      if (f[t][i] == 0) continue;
      for (int k = 0; k <= N - i; ++ k) {
        for (int j = k; j <= N; ++ j) {
          f[t + 1][i + k] += f[t][i] * Q[j] * calc(i, j, k);
        }
      }
    }
  }
  flt ret = 0;
  for (int i = 1; i <= L; ++ i) {
    ret += i * (f[i][N] - f[i - 1][N]);
  }
  printf("%.10f\n", ret);
  return 0;
}