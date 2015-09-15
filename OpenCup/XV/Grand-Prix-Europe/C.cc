#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
vector<int> G[MAXN], pt[MAXN];
bool path[MAXN][MAXN], mt[20][20];
int dp[MAXN], g[1 << 10], n, m;

bool check(int u, int v) {
    for (auto &a : pt[u]) for (auto &b : pt[v])
        if (path[a][b]) return true;
    return false;
}

void solve(int u, int f = -1) {
    for (auto &v : G[u]) if (v != f) solve(v, u);
    dp[u] = 0; pt[u].clear(); pt[u].push_back(u);
    vector<int> nd;
    for (auto &v : G[u]) if (v != f) {
        dp[u] += dp[v];
        if (check(u, v)) ++ dp[u];
        else nd.push_back(v);
    }
    for (size_t i = 0; i < nd.size(); ++ i) {
        for (size_t j = i + 1; j < nd.size(); ++ j) {
            mt[i][j] = mt[j][i] = check(nd[i], nd[j]);
        }
    }
    int ret = 0, S = 1 << nd.size(), now = 0;
    for (int msk = 0; msk < S; ++ msk) {
        g[msk] = 0;
        for (size_t i = 0; i < nd.size(); ++ i) {
            for (size_t j = i + 1; j < nd.size(); ++ j) {
                if (((msk >> i) & 1) && ((msk >> j) & 1) && mt[i][j]) {
                    g[msk] = max(g[msk], g[msk ^ (1 << i) ^ (1 << j)] + 1);
                }
            }
        }
        if (g[msk] == ret) now |= (S - 1) ^ msk;
        else if (g[msk] > ret) ret = g[msk], now = (S - 1) ^ msk;
    }
    dp[u] += ret;
    for (size_t i = 0; i < nd.size(); ++ i) if ((now >> i) & 1) {
        for (auto &v : pt[nd[i]]) pt[u].push_back(v);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++ i) {
            G[i].clear();
            for (int j = 0; j < n; ++ j) path[i][j] = 0;
        }
        for (int i = 1; i < n; ++ i) {
            int u, v; scanf("%d%d", &u, &v); -- u; -- v;
            G[u].push_back(v); G[v].push_back(u);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++ i) {
            int u, v; scanf("%d%d", &u, &v); -- u, -- v;
            path[u][v] = path[v][u] = 1;
        }
        solve(0);
        printf("%d\n", dp[0]);
    }
    return 0;
}