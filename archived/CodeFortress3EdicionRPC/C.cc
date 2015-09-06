#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    printf("%lld\n", (LL)m * n - n * (n + 1) / 2);
  }
  return 0;
}
