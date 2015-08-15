#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, r(0), p; scanf("%d%d", &n, &p);
    for (int i = 1; i < n; ++ i) {
      int x; scanf("%d", &x);
      r += x > p; p = x;
    }
    printf("%d\n", r);
  }
  return 0;
}
