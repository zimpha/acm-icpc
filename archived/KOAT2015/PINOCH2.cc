#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, r(0), c(0), p; scanf("%d%d", &n, &p);
    for (int i = 1; i < n; ++ i) {
      int x; scanf("%d", &x);
      if (x == p) ++ c;
      else c = 0;
      r = max(r, c); p = x;
    }
    printf("%d\n", r);
  }
  return 0;
}
