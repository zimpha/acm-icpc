#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
int g[MAXN][MAXN], dp[MAXN][MAXN];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            scanf("%d", &g[i][j]);
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = m; j >= 1; -- j) {
            dp[i][j] = dp[i - 1][j + 1] + g[i][j];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j + 1]);
        }
    }
    printf("%d\n", dp[n][1]);
    return 0;
}
