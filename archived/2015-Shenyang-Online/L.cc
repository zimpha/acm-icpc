#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 1000000 + 10;
const LL inf = 1ll << 61;
int t[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    LL ret(-inf);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", t + i);
    }
    LL mx = (LL)t[0] * b;
    for (int i = 1; i < n; ++ i) {
      ret = max(ret, (LL)a * t[i] * t[i] + mx);
      mx = max(mx, (LL)t[i] * b);
    }
    mx = (LL)t[n - 1] * b;
    for (int i = n - 2; i >= 0; -- i) {
      ret = max(ret, (LL)a * t[i] * t[i] + mx);
      mx = max(mx, (LL)t[i] * b);
    }
    printf("Case #%d: %lld\n", cas, ret);
  }
  return 0;
}
