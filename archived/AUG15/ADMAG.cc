#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    LL n; scanf("%lld", &n);
    if (n <= 3) {printf("%d\n", (int)n); continue;}
    LL f1 = 1, f2 = 1, s = 2;
    int ret = 2;
    while (s < n) {
      LL w = f1 + f2;
      s += w;
      ++ ret;
      f1 = f2; f2 = w;
    }
    printf("%d\n", ret);
  }
  return 0;
}