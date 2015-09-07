#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int P = 1e9 + 7, MAXN = 1e6 + 10;
int rv[MAXN], f[MAXN], g[MAXN];
LL pm(LL a, LL n, LL m) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % m;
    a = a * a % m;
  }
  return r;
}

int main() {
  f[0] = f[1] = 1; g[0] = g[1] = 1;
  rv[1] = 1; rv[0] = 0;
  for (int i = 2; i < MAXN; ++ i) {
    rv[i] = rv[P % i] * LL(P - P / i) % P;
    f[i] = (LL)i * f[i - 1] % P;
    g[i] = (LL)rv[i] * g[i - 1] % P;
  }
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    int f0 = pm(2, (pm(2, n, P - 1) - n + P - 1) % (P - 1), P);
    int c = (LL)f[n] * g[n - k] % P * g[k] % P;
    printf("%lld\n", (LL)c * f0 % P);
  }
  return 0;
}
