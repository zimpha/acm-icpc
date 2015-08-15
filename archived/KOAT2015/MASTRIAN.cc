#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int P = 1e9 + 7;

LL s2(LL n) {
  n %= P;
  return n * (n + 1) % P * (2 * n + 1) % P * 166666668 % P;
}
LL s1(LL n) {
  n %= P;
  return n * (n + 1) / 2 % P;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    LL n, m; scanf("%lld%lld", &n, &m);
    LL ret = s2(min(n, m)) + abs(n - m) % P * s1(min(n, m));
    ret %= P; ret *= 2; ret %= P;
    printf("%lld\n", ret);
  }
  return 0;
}
