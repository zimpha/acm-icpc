#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10, inf = 1e9;
char s[MAXN];
int dp[MAXN][10];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 0; i < 9; ++ i) dp[0][i] = inf;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++ i) {
      int d = s[i] - '0';
      for (int j = 0; j < 9; ++ j) dp[i][j] = inf;
      for (int j = (i == 1 && n != 1); j <= 9; ++ j) {
        for (int k = 0; k < 9; ++ k) {
          int nw = (k * 10 + j) % 9;
          dp[i][nw] = min(dp[i][nw], dp[i - 1][k] + abs(j - d));
        }
      }
    }
    printf("%d\n", dp[n][0]);
  }
  return 0;
}
