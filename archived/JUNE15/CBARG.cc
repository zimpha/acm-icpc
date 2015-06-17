#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, p(0); scanf("%d", &n);
    LL ret(0);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      if (x > p) ret += x - p;
      p = x;
    }
    printf("%lld\n", ret);
  }
  return 0;
}

