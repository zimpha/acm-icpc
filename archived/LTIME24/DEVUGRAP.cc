#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, k; scanf("%d%d", &n, &k);
    LL ret = 0;
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      int y = x % k;
      if (x >= k) ret += min(y, k - y);
      else ret += k - y;
    }
    cout << ret << endl;
  }
  return 0;
}
