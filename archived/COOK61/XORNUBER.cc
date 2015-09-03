#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    if (n == 1) puts("2");
    else if (n % 2 == 0) puts("-1");
    else {
      int f(1);
      for (int x = n; x; x >>= 1) {
        if (x % 2 == 0) f = 0;
      }
      if (f) printf("%d\n", n / 2);
      else puts("-1");
    }
  }
  return 0;
}

