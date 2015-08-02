#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10, SZ = MAXN * MAXN;

int a[MAXN], b[SZ], n, m;

LL solve(int n, int a[]) {
  LL ret(0);
  sort(a, a + n);
  for (int i = 0; i < n; ++ i) {
    ret += 2 * (LL(i) * a[i] - LL(n - i - 1) * a[i]);
  }
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n); m = 0;
    for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    for (int i = 0; i < n; ++ i) {
      for (int j = i + 1; j < n; ++ j) {
        b[m ++] = a[i] + a[j];
      }
    }
    LL ret = solve(m, b) - LL(n - 2) * solve(n, a);
    printf("%lld\n", ret);
  }
  return 0;
}