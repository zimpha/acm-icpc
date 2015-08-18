#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10, inf = 1e9;

char L[2][MAXN];
int dp[2][MAXN], n;

inline void upd(int &x, int y) {
  if (y < x) x = y;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%s%s", L[0], L[1]);
    n = strlen(L[0]);
    fill(dp[0], dp[0] + n, inf);
    fill(dp[1], dp[1] + n, inf);
    if (L[0][0] == '.') dp[0][0] = 0;
    if (L[1][0] == '.') dp[1][0] = 0;
    for (int i = 0; i < n - 1; ++ i) {
      for (int o = 0; o < 2; ++ o) if (dp[o][i] != inf) {
        if (L[o][i + 1] == '.') upd(dp[o][i + 1], dp[o][i]);
        if (L[o ^ 1][i] == '.') upd(dp[o ^ 1][i], dp[o][i] + 1);
        if (L[o ^ 1][i + 1] == '.') upd(dp[o ^ 1][i + 1], dp[o][i] + 1);
      }
    }
    int ret = min(dp[0][n - 1], dp[1][n - 1]);
    if (ret == inf) puts("No");
    else puts("Yes");
    if (ret != inf) printf("%d\n", ret);
  }
  return 0;
}