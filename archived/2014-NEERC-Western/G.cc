#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 60, MOD = 1e9 + 7;
int dp1[MAXN][MAXN];
int dp3[MAXN][MAXN];
int dp2[MAXN][MAXN][MAXN];
int f[MAXN], g[MAXN], C[MAXN][MAXN];
int fac[MAXN], inv[MAXN];

LL calc1(int N, int B);
LL calc2(int N, int B, int K);
LL calc3(int N, int B);

LL pm(LL a, LL n) {
  LL r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

LL calc1(int N, int B) {
  if (B >= N && N) return 0;
  int &ret = dp1[N][B];
  if (ret != -1) return ret;
  if (B == 0) {
    ret = g[N];
    for (int b = 1; b < N; ++ b) {
      ret -= calc1(N, b);
      ret = (ret + MOD) % MOD;
    }
    return ret;
  }
  ret = 0;
  for (int i = 1; i < N; ++ i) {
    for (int k = 1; k <= B; ++ k) {
      LL tmp = calc2(N - i, B - k, k) * inv[k] % MOD;
      tmp = tmp * calc1(i, 0) % MOD;
      tmp = tmp * C[N - 1][i - 1] % MOD;
      tmp = tmp * pm(i, k) % MOD;
      ret = (ret + tmp) % MOD;
    }
  }
  return ret;
}

LL calc2(int N, int B, int K) {
  if (B >= N && N) return 0;
  int &ret = dp2[N][B][K];
  if (ret != -1) return ret;
  if (K == 0) return ret = (N == 0 && B == 0);
  ret = 0;
  for (int i = 1; i <= N; ++ i) {
    for (int b = 0; b <= B; ++ b) {
      LL tmp = calc3(i, b) * C[N][i] % MOD;
      tmp = tmp * calc2(N - i, B - b, K - 1) % MOD;
      ret = (ret + tmp) % MOD;
    }
  }
  return ret;
}

LL calc3(int N, int B) {
  if (B >= N && N) return 0;
  int &ret = dp3[N][B];
  if (ret != -1) return ret;
  if (B == 0) return ret = calc1(N, 0) * N % MOD;
  ret = 0;
  for (int i = 1; i < N; ++ i) {
    for (int k = 1; k <= B; ++ k) {
      LL tmp = calc2(N - i, B - k, k) * inv[k] % MOD;
      tmp = tmp * calc1(i, 0) % MOD * i % MOD;
      tmp = tmp * C[N][i] % MOD * pm(i, k) % MOD;
      ret = (ret + tmp) % MOD;
    }
  }
  return ret;
}

void init() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    fac[i] = (LL)i * fac[i - 1] % MOD;
    inv[i] = pm(fac[i], MOD - 2);
  }
  for (int i = 0; i < MAXN; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++ j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  g[0] = g[1] = 1; f[0] = f[1] = 1;
  for (int n = 2; n < MAXN; ++ n) {
    f[n] = g[n] = pm(2, n * (n - 1) / 2);
    for (int k = 1; k < n; ++ k) {
      g[n] -= (LL)C[n - 1][k - 1] * g[k] % MOD * f[n - k] % MOD;
      g[n] = (g[n] + MOD) % MOD;
    }
  }  
}

int main() {
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  memset(dp3, -1, sizeof(dp3));
  int N, B; scanf("%d%d", &N, &B);
  int ret = 0; init();
  for (int b = 0; b <= B; ++ b) {
    ret = (ret + calc1(N, b)) % MOD;
  }
  printf("%d\n", ret);
  return 0;
}