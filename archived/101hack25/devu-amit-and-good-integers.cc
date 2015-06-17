#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
LL s[MAXN];

int main() {
  int T, n, l, r; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      if (l <= x && x <= r) s[i] = 0;
      else s[i] = min(abs(x - l), abs(x - r));
    }
    sort(s, s + n, greater<LL>()); s[n] = 0;
    for (int i = n - 1; i >= 0; -- i) s[i] += s[i + 1];
    for (int i = 1; i <= n; ++ i) {
      printf("%lld%c", s[i - 1], " \n"[i == n]);
    }
  }
  return 0;
}

