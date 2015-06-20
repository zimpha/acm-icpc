#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;

LL dp[MAXN][MAXN], sum[MAXN];
int p[MAXN], n, m, k;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= k; ++ j) {
            dp[i][j] = dp[i - 1][j];
            if (i >= m) {
                dp[i][j] = max(dp[i][j], dp[i - m][j - 1] + sum[i] - sum[i - m]);
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
