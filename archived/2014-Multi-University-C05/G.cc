#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
const int SIZE = 100, MOD = 1e9 + 7;

vector<int> G[SIZE];
int deg[SIZE];
int C[SIZE][SIZE];
int H[SIZE][SIZE], map[SIZE][SIZE], vis[SIZE];
int dp[1 << 22];
vector<int> nodes;
int n, m, ret, N, now;

void dfs(int u) {
    vis[u] = true; nodes.push_back(u);
    for (int v = 1; v <= n; ++ v) {
        if (!vis[v] && H[u][v]) dfs(v);
    }
}

int solve(int mask) {
    if (dp[mask] != -1) return dp[mask];
    if (mask == (1 << N) - 1) return dp[mask] = 1;
    dp[mask] = 0;
    for (int i = 0; i < N; ++ i) {
        if ((mask >> i) & 1) continue;
        if (deg[i]) continue;
        for (int j = 0; j < (int)G[i].size(); ++ j) -- deg[G[i][j]];
        dp[mask] += solve(mask | (1 << i));
        dp[mask] %= MOD;
        for (int j = 0; j < (int)G[i].size(); ++ j) ++ deg[G[i][j]];
    }
    return dp[mask];
}

void gao() {
    N = nodes.size();
    for (int i = 0; i < N; ++ i) {
        G[i].clear();
        deg[i] = 0;
    }
    for (int i = 0; i < (1 << N); ++ i) dp[i] = -1;
    for (int i = 0; i < N; ++ i) {
        for (int j = 0; j < N; ++ j) {
            if (map[nodes[i]][nodes[j]]) {
                ++ deg[j];
                G[i].push_back(j);
            }
        }
    }
    ret = (LL)ret * solve(0) % MOD;
    now += N;
    ret = (LL)ret * C[now][N] % MOD;
}

int main() {
    for (int i = 0; i < SIZE; ++ i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
    while (scanf("%d%d", &n, &m) == 2) {
        memset(map, 0, sizeof(map));
        memset(H, 0, sizeof(H));
        for (int i = 0; i < m; ++ i) {
            int x, y; scanf("%d%d", &x, &y);
            map[x][y] = 1;
            H[y][x] = H[x][y] = 1;
        }
        ret = 1; now = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++ i) {
            if (!vis[i]) {
                nodes.clear();
                dfs(i);
                gao();
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
