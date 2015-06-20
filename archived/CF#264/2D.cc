#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;

vector<int> p[MAXN], G[MAXN];
int dp[MAXN], n, m;

int dfs(int u) {
    if (dp[u]) return dp[u];
    for (auto v : G[u]) {
        dp[u] = max(dp[u], dfs(v));
    }
    return ++ dp[u];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            int x; cin >> x; x --;
            p[x].push_back(j);
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            bool flag = true;
            for (int k = 0; k < m && flag; ++ k) {
                if (p[i][k] >= p[j][k]) flag = false;
            }
            if (flag) G[i].push_back(j);
        }
    }
    int ret = 0;
    for (int i = 0; i < n; ++ i) {
        if (dp[i] == 0) dp[i] = dfs(i);
        ret = max(ret, dp[i]);
    }
    cout << ret << endl;
    return 0;
}
