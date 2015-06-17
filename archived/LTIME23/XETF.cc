#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300 + 10, MOD = 1e9 + 7;

LL stirling[MAXN][MAXN], inv[MAXN];
LL pm(LL a, LL n) {
  LL r = 1; a %= MOD;
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}
LL sum(LL n, LL m) {
  n %= MOD;
  if (m == 0) return n;
  LL ret = 0, pd = 1;
  for (int j = 0; j <= m; ++ j) {
    pd = pd * (n + 1 - j) % MOD;
    ret += stirling[m][j] * pd % MOD * inv[j + 1] % MOD;
  }
  return ret % MOD;
}

int main() {
  stirling[0][0] = 1; inv[0] = 0;
  for (int n = 1; n < MAXN; ++ n) {
    inv[n] = pm(n, MOD - 2);
    for (int k = 1; k <= n; ++ k) {
      stirling[n][k] = (stirling[n - 1][k - 1] + stirling[n - 1][k] * k) % MOD;
    }
  } 
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    LL n, m; scanf("%lld%lld", &n, &m);
    if (n <= 10000) {
      LL ret = 0;
      for (int i = 1; i <= n; ++ i) {
        if (__gcd(i, (int)n) == 1) ret += pm(i, m);
      }
      printf("%lld\n", ret % MOD);
      continue;
    }
    vector<LL> pl;
    LL x = n;
    for (LL i = 2; i * i <= n; ++ i) {
      if (n % i == 0) {
        pl.push_back(i);
        while (n % i == 0) n /= i;
      }
    }
    if (n > 1) pl.push_back(n); n = x;
    LL ret = 0;
    for (int msk = 0; msk < (1 << pl.size()); ++ msk) {
      LL pd = 1, sgn = 1;
      for (size_t i = 0; i < pl.size(); ++ i) {
        if (msk >> i & 1) pd *= pl[i], sgn = -sgn;
      }
      if (sgn == 1) ret += pm(pd, m) * sum(n / pd, m) % MOD;
      else ret -= pm(pd, m) * sum(n / pd, m) % MOD;
    }
    ret %= MOD; if (ret < 0) ret += MOD;
    printf("%lld\n", ret);
  }
  return 0;
}
