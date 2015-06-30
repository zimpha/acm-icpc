#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL dp[5010][110];

int main() {
  vector<int> a;
  for (int i = 1; i <= 70; ++ i) a.push_back(i * i);
  dp[0][0] = 1;
  for (int i = 0; i < 70; ++ i) {
    for (int k = 0; k <= 5000; ++ k) {
      for (int n = 0; n <= 100; ++ n) {
        if (k >= a[i] && n >= 1) {
          dp[k][n] += dp[k - a[i]][n - 1];
        }
      }
    }
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, k; scanf("%d%d", &n, &k);
    printf("%lld\n", dp[k][n]);
  }
  return 0;
}

