#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    LL a, b; scanf("%lld%lld", &a, &b);
    LL r1(0), r2(0);
    for (int i = 0; i < 63; ++ i) {
      int a1 = a & 1, b1 = b & 1;
      a >>= 1; b >>= 1;
      if (!((!a1) && (!b1) && a == b)) r1 |= 1ll << i;
      if (a1 && b1 && a == b) r2 |= 1ll << i;
    }
    printf("Case %d: %lld %lld\n", cas, r1, r2);
  }
  return 0;
}

