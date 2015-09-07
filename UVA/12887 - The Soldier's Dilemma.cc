#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 50000 + 10, MOD = 1e9 + 7;
int fac[MAXN], inv[MAXN];

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    fac[i] = (LL)i * fac[i - 1] % MOD;
    inv[i] = pm(fac[i], MOD - 2);
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    LL ret = (LL)fac[n * 2] * inv[n] % MOD * inv[n + 1] % MOD;
    printf("%lld\n", ret);
  }
  return 0;
}

