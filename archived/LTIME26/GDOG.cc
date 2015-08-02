#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m, ret(0); scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
      ret = max(ret, n % i);
    }
    printf("%d\n", ret);
  }
  return 0;
}