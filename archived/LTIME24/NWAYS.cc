#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9 + 7, MAXN = 2000000 + 10;
LL fac[MAXN];
LL pw(LL a, LL n) {
  LL r = 1;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}
LL inv(LL x) {return pw(x, MOD - 2);}
LL NCR(LL n, LL r) {
  return fac[n] * inv(fac[r]) % MOD * inv(fac[n - r]) % MOD;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; ++ i) fac[i] = fac[i - 1] * i % MOD;
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N, K; scanf("%d%d", &N, &K);
    if (N == 1) {puts("1"); continue;}
    LL ret = MOD - N;
    ret += NCR(N + K, K + 1) * N * 2 % MOD;
    ret -= NCR(N + K, K + 2) * (K + 1) * 2 % MOD;
    ret %= MOD; ret += MOD; ret %= MOD;
    printf("%lld\n", ret);
  }
  return 0;
}
