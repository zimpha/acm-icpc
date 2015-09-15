#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600 + 10;
vector<int> t;
int a[MAXN], b[MAXN], d[MAXN];
int dp[MAXN][MAXN], n;

int solve(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int mx = -1;
    for (int i = 0; i < n; ++ i) {
        if (a[i] >= l && b[i] <= r) {
            mx = max(mx, d[i]);
        }
    }
    if (mx == -1) return dp[l][r] = 0;
    dp[l][r] = 1e9;
    for (int i = l; i <= r; ++ i) {
        dp[l][r] = min(dp[l][r], solve(l, i - 1) + solve(i + 1, r));
    }
    dp[l][r] += mx;
    return dp[l][r];
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &n); t.clear();
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d%d", a + i, b + i, d + i);
            t.push_back(a[i]);
            t.push_back(b[i]);
        }
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        for (int i = 0; i < n; ++ i) {
            a[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
            b[i] = lower_bound(t.begin(), t.end(), b[i]) - t.begin();
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, t.size() - 1));
    }
    return 0;
}
