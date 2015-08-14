#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 300 + 10, MAXW = 60;

int dp[MAXW][MAXN], pv[MAXW][MAXN];
int p[MAXW][MAXN], s[MAXW][MAXN];
int K[MAXW], N, W;

int solve(int w, int n) {
  if (n <= 0) return 0;
  if (w > W) return 0;
  if (dp[w][n] != -1) return dp[w][n];
  int ret = 0;
  for (int i = 0; i < K[w]; ++ i) {
    int cost = min(n, s[w][i]) * p[w][i];
    if (ret < solve(w + 1, n - s[w][i]) + cost) {
      ret = solve(w + 1, n - s[w][i]) + cost;
      pv[w][n] = i;
    }
  }
  return dp[w][n] = ret;
}

int main() {
  while (scanf("%d%d", &N, &W) == 2) {
    for (int i = 0; i <= W; ++ i) {
      scanf("%d", K + i);
      for (int j = 0; j < K[i]; ++ j) scanf("%d", &p[i][j]);
      for (int j = 0; j < K[i]; ++ j) scanf("%d", &s[i][j]);
    }
    memset(dp, -1, sizeof(dp));
    int ret = solve(0, N);
    printf("%d\n%d\n", ret, p[0][pv[0][N]]);
  }
  return 0;
}

