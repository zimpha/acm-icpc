#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2000 + 10;
LL f[MAXN], g[MAXN], p[MAXN], MOD;

int main() {
  int T; scanf("%d%lld", &T, &MOD);
  for (int i = p[0] = 1; i < MAXN; ++ i) p[i] = p[i - 1] * 2 % MOD;
  for (int i = 1; i < MAXN; ++ i) {
    for (int k = 1; k < i; ++ k) {
      f[i] = (f[i] + p[i - 1 - k] * k * (i - k) + f[i - k]) % MOD;
    }
  }
  for (int i = 1; i < MAXN; ++ i) {
    for (int k = 1; k < i; ++ k) {
      LL t1 = k * (i - k), t2 = t1 * t1 % MOD;
      t2 = t2 * p[i - 1 - k] % MOD;
      g[i] = (g[i] + t2 + g[k] + t1 * 2 * f[i - k]) % MOD;
    }
  }
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    printf("%lld\n", g[n]);
  }
  return 0;
}
