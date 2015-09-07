#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10;
double dp[MAXN][MAXN];
int a, b, n;

int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d/%d%d", &a, &b, &n);
        memset(dp, 0, sizeof(dp)); dp[0][0] = 1.0;
        for (int i = 1; i <= n; ++ i) {
            for (int j = 0; j * b <= a * i; ++ j) {
                dp[i][j] = dp[i - 1][j] * (b - a) / b;
                if (j) dp[i][j] += dp[i - 1][j - 1] * a / b;
            }
        }
        double p = 0;
        for (int j = 0; j * b <= a * n; ++ j) p += dp[n][j];
        printf("Case #%d: %d\n", cas, (int)(1.0 / p));
    }
    return 0;
}
