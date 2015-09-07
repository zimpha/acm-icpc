#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;

double p[MAXN], dp[MAXN];
int n, m, k;

int main() {
    int T; scanf("%d", &T);
    for (int cas = 1; cas<= T; ++ cas) {
        scanf("%d%d%d", &n, &k, &m);
        for (int i = 0; i < n; ++ i) scanf("%lf", p + i);
        dp[0] = 0; dp[1] = p[0];
        for (int i = 2; i <= m; ++ i) {
            dp[i] = 0;
            for (int j = 0; j < n; ++ j) dp[i] += p[j] * pow(dp[i - 1], j);
        }
        printf("Case #%d: %.10f\n", cas, pow(dp[m], k));
    }
    return 0;
}
