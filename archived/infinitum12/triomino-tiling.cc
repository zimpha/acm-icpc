#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 10000 * 10000 / 3 + 10, MOD = 1e9 + 7;
LL fac[MAXN];

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int main() {
  fac[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N, M; scanf("%d%d", &N, &M);
    if (N * M % 3 != 0) {puts("0"); continue;}
    if (N % 3) swap(N, M);
    LL ret = fac[N * M / 3], rv = 1;
    for (int i = 0; i < M; ++ i) {
      ret = ret * fac[i / 3] % MOD;
      rv = rv * fac[i / 3 + N / 3] % MOD;
    }
    ret = ret * pm(rv, MOD - 2) % MOD;
    printf("%lld\n", ret);
  }
  return 0;
}
