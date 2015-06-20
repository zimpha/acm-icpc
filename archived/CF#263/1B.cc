#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10, MOD = 1e9 + 7;
vector<int> G[MAXN];
long long dp[MAXN][2], x[MAXN], n;

void dfs(int u) {
    dp[u][0] = 1, dp[u][1] = 0;
    for (auto v : G[u]) {
        dfs(v);
        dp[u][1] *= dp[v][0];
        dp[u][1] += dp[u][0] * dp[v][1];
        dp[u][0] *= dp[v][0];
        dp[u][1] %= MOD; dp[u][0] %= MOD;
    }
    if (x[u]) dp[u][1] = dp[u][0];
    else dp[u][0] += dp[u][1];
    dp[u][1] %= MOD; dp[u][0] %= MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; ++ i) {
        int f; cin >> f;
        G[f].push_back(i);
    }
    for (int i = 0; i < n; ++ i) cin >> x[i];
    dfs(0);
    cout << dp[0][1] << endl;
    return 0;
}
