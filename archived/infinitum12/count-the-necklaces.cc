#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int main() {
  int n, k; scanf("%d%d", &n, &k);
  LL ret(0);
  for (int i = 1; i <= n; ++ i) {
    int g = __gcd(n, i);
    ret += pm(k, g);
  }
  ret %= MOD;
  ret = ret * pm(n, MOD - 2) % MOD;
  printf("%d\n", (int)ret);
  return 0;
}

