#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000 + 10, MOD = 1e9 + 7;

typedef long long LL;
LL dp[MAXN][MAXN];
int a[MAXN];
int n, h;

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
    dp[1][0] = (a[1] == h || a[1] + 1 == h ? 1 : 0);
    dp[1][1] = (a[1] + 1 == h ? 1 : 0);
    for (int i = 2; i <= n; ++ i) {
        for (int open = max(0, h - a[i] - 1); open <= min(h - a[i], i); ++ open) {
            if (a[i] + open == h) {
                dp[i][open] += dp[i - 1][open];
                if (open) dp[i][open] += dp[i - 1][open - 1];
            }
            if (a[i] + open + 1 == h) {
                dp[i][open] += dp[i - 1][open + 1] * (open + 1);
                dp[i][open] += dp[i - 1][open];
                dp[i][open] += dp[i - 1][open] * open;
            }
            dp[i][open] %= MOD;
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}
