#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
unordered_map<int, LL> dp;

LL solve(int n) {
  if (dp.count(n)) return dp[n];
  LL &ret = dp[n]; ret = (LL)n * n;
  for (int i = 2, j; i <= n; i = j + 1) {
    j = n / (n / i);
    ret -= LL(j - i + 1) * solve(n / i);
  }
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, d; scanf("%d%d", &n, &d);
    n /= d;
    printf("%lld\n", (solve(n) + 1) / 2);
  }
}