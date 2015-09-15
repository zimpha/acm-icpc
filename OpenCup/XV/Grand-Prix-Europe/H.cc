#include <bits/stdc++.h>
#define v first
#define c second
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 150000 + 10, inf = 1e9;
PII item[MAXN];
int dp[10][MAXN], n, k;

int main() {
    int T; scanf("%d", &T);
    for (int _ = 0; _ < T; ++ _) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", &item[i].v, &item[i].c);
        }
        sort(item, item + n);
        dp[0][n] = -inf;
        for (int i = n - 1; i >= 0; -- i) dp[0][i] = max(dp[0][i + 1], item[i].v - item[i].c);
        for (int j = 1; j <= k; ++ j) {
            dp[j][n] = -inf;
            for (int i = n - 1; i >= 0; -- i) {
                dp[j][i] = max(dp[j][i + 1], min(dp[j - 1][i + 1] - item[i].c, item[i].v - item[i].c));
                if (i + j > n) dp[j][i] = -inf;
            }
        }
        printf("%d\n", max(0, dp[k][0]));
    }
    return 0;
}