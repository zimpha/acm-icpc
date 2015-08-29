#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 150 + 10;
const LL inf = 1ll << 60;

LL dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int r[MAXN], s[MAXN], a[MAXN];
int n, A, B;

int main() {
  while (scanf("%d%d%d", &n, &A, &B) == 3) {
    for (int i = 0; i < n; ++ i) scanf("%d%d", r + i, a + i);
    s[n] = 0;
    for (int i = n - 1; i >= 0; -- i) s[i] = a[i] + s[i + 1];
    memset(vis, 0, sizeof(vis));
    vis[n][0] = 1; dp[n][0] = -inf;
    for (int i = n - 1; i >= 0; -- i) {
      for (int j = 0; j <= s[0]; ++ j) {
        dp[i][j] = inf;
        if (j >= a[i]) { // take i
          int lim = s[i + 1] - (j - a[i]);
          for (int k = 0; k <= lim; ++ k) vis[i][j] |= vis[i + 1][k];
          if (vis[i][j]) {
            LL res(-inf);
            for (int k = lim + 1; k <= s[0]; ++ k) {
              if (vis[i + 1][k]) res = max(res, - dp[i + 1][k] + 1 - r[i]);
            }
            dp[i][j] = min(dp[i][j], res);
          }
        }
        // pass i
        bool flag(0);
        for (int k = j; k <= s[0]; ++ k) flag |= vis[i + 1][k];
        if (!flag) continue; vis[i][j] |= flag;
        LL res(inf);
        for (int k = j; k <= s[0]; ++ k) if (vis[i + 1][k]) {
          res = min(res, dp[i + 1][k] + 1 + r[i]);
        }
        dp[i][j] = min(dp[i][j], max(res, 1ll));
      }
    }
    for (int ret = s[0]; ret >= 0; -- ret) {
      if (dp[0][ret] <= A - B && vis[0][ret]) {
        printf("%d %d\n", ret, s[0] - ret);
        break;
      }
    }
  }
  return 0;
}