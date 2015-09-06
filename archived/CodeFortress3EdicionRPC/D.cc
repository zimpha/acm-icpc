#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, d; scanf("%d%d", &n, &d);
    LL ret(1);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      x -= d;
      LL g = __gcd((LL)x, ret);
      ret /= g; ret *= x;
    }
    printf("%lld\n", ret);
  }
  return 0;
}
