#include <bits/stdc++.h>
using namespace std;
int dp[1 << 16], n, m;

int main() {
    scanf("%d%d", &n, &m);
    memset(dp, 0x7f, sizeof(dp)); dp[0] = 0;
    for (int _ = 0; _ < n; ++ _) {
        int d, c[20]; scanf("%d", &d);
        for (int i = 0; i < m; ++ i) scanf("%d", c + i);
        for (int msk = 1, r; msk < (1 << m); ++ msk) {
            for (int i = r = 0; i < m; ++ i) {
                if ((msk >> i) & 1) r += c[i];
            }
            dp[msk] = min(dp[msk], r + d);
        }
    }
    for (int msk = 1; msk < (1 << m); ++ msk) {
        for (int sub = (msk - 1) & msk; sub; sub = (sub - 1) & msk) {
            dp[msk] = min(dp[msk], dp[sub] + dp[msk ^ sub]);
        }
    }
    printf("%d\n", dp[(1 << m) - 1]);
    return 0;
}