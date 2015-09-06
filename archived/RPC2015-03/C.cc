#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a[100];

int main() {
  a[0] = 0; a[1] = 1;
  for (int i = 2; i < 23; ++ i) {
    a[i] = a[i - 1] * 6 - a[i - 2] + 2;
  }
  for (LL n; scanf("%lld", &n), n; ) {
    int ret = 0;
    for (int i = 2; i < 23; ++ i) ret += a[i] <= n;
    printf("%d\n", ret);
  }
  return 0;
}
