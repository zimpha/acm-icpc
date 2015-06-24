#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[110][110][2], n, m, d;

int main() {
    cin >> n >> m >> d;
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j <= n; ++ j) {
            for (int e = 0; e < 2; ++ e) {
                for (int k = 1; k <= m && j + k <= n; ++ k) {
                    dp[i + 1][j + k][e | (k >= d)] += dp[i][j][e];
                    dp[i + 1][j + k][e | (k >= d)] %= MOD;
                }
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; ++ i) {
        ret += dp[i][n][1];
        ret %= MOD;
    }
    cout << ret << endl;
    return 0;
}
