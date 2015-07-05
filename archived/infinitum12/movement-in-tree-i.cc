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
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int d, h, k; scanf("%d%d%d", &d, &k, &h);
    LL ret(0);
    if (d == 1) ret = k + 1;
    else {
      ret = pm(d, k + 1) - 1;
      ret = ret * pm(d - 1, MOD - 2) % MOD;
      ret += MOD; ret %= MOD;
    }
    printf("%d\n", (int)ret);
  }
  return 0;
}

