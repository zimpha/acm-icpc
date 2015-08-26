#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10, MOD = 1e9 + 7;
int inv[MAXN];

LL pm(LL a, LL n) {
  LL r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

LL C(LL n, int m) {
  if (m < 0 || n < 0 || n < m) return 0;
  LL r = 1;
  for (int i = 1; i <= m; ++ i) {
    r = (n - i + 1) % MOD * r % MOD * inv[i] % MOD;
  }
  return r;
}

int main() {
  for (int i = 1; i < MAXN; ++ i) inv[i] = pm(i, MOD - 2);
  LL N, D, X;
  while (scanf("%lld%lld%lld", &N, &D, &X) == 3 && N) {
    LL ret = 0;
    for (int k = 0; X * k <= N && k <= D; ++ k) {
      LL now = C(N + D - 1 - k * X, N - k * X);
      LL coef = C(D, k);
      if (k & 1) ret -= now * coef % MOD;
      else ret += now * coef % MOD;
      ret = (ret + MOD) % MOD;
    }
    printf("%lld\n", ret);  
  }
  return 0;
}