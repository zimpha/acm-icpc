#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXF = 1000 + 10, MAXN = 2003 + 10, MOD = 2003;

int poly[MAXF][MAXF], P[MAXN], Q[MAXN];

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int main() {
  poly[0][0] = 1;
  for (int i = 1; i < MAXF; ++ i) {
    for (int j = 0; j < i; ++ j) {
      poly[i][j + 1] += poly[i - 1][j];
      if (j) poly[i][j] += poly[i - 1][j] * j;
    }
    for (int j = 0; j <= i; ++ j) poly[i][j] %= MOD;
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, k, l, f; scanf("%d%d%d%d", &n, &k, &l, &f);
    if (f == 1) {
      int rv = pm(k, MOD - 2);
      int ret = pm(rv, l);
      for (int i = n; i > n - l; -- i) {
        ret = i % MOD * ret % MOD;
      }
      printf("%d\n", ret);
      continue;
    }
    int lp = 1, lf = f + 1; P[0] = 1;
    for (int i = 1; i <= l; ++ i) {
      for (int j = 0; j < lp + lf && j < MAXN; ++ j) Q[j] = 0;
      for (int j = 0; j < lp; ++ j) {
        for (int k = 0; k < lf; ++ k) {
          Q[j + k] += P[j] * poly[f][k] % MOD;
        }
      }
      lp = min(lp + lf - 1, MAXN);
      for (int j = 0; j < lp; ++ j) P[j] = Q[j] % MOD;
    }
    int ret(0), rv = pm(k, MOD - 2), mul(1);
    for (int a = 0; a < lp; ++ a) {
      ret += mul * P[a] % MOD * pm(rv, a) % MOD;
      mul = (n - a) % MOD * mul % MOD;
    }
    printf("%d\n", ret % MOD);
  }
  return 0;
}