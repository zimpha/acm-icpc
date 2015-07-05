#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n); -- n;
    LL r(1), m = 1e9 + 7, a(2);
    for (; n; n >>= 1) {
      if (n & 1) r = r * a % m;
      a = a * a % m;
    }
    printf("%d\n", (int)r);
  }
  return 0;
}

