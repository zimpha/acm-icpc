#include <bits/stdc++.h>
using namespace std;

int main() {
  int ret(0), n, mx(1e9);
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    ret += x; if (x & 1) mx = min(mx, x);
  }
  if (mx == ret) puts("NIESTETY");
  else printf("%d\n", (ret & 1) ? ret - mx : ret);
  return 0;
}