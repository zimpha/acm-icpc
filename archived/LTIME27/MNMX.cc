#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, r(1e9); scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      r = min(r, x);
    }
    printf("%lld\n", (LL)r * (n - 1));
  }
  return 0;
}

