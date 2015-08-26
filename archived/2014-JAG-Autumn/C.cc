#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double flt;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

vector<flt> p, dp;
int n;

int main() {
  while (scanf("%d", &n) == 1 && n) {
    flt sum = 0; p.clear();
    for (int i = 0; i < n; ++ i) {
      flt x; scanf("%lf", &x);
      if (x == 1.00) sum += 1.0;
      else {
        if (sum > 0) p.push_back(sum), sum = 0;
        p.push_back(x);
      }
    }
    if (sum > 0) p.push_back(sum);
    n = p.size();
    dp.resize(n + 1); dp[n] = 0;
    for (int i = n - 1; i >= 0; -- i) {
      flt now = 0; dp[i] = 1e9;
      for (int j = i + 1; j <= n && j - i <= 50; ++ j) {
        if (p[j - 1] < 1.0) now = (now + 1.0) / p[j - 1];
        else now += p[j - 1];
        dp[i] = min(dp[i], now + dp[j] + 1);
      }
    }
    printf("%.10f\n", dp[0] - 1);
  }
  return 0;
}