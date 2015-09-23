#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;
typedef pair<int, int> PII;
vector<PII> G[MAXN][MAXN];
bool dp[MAXN][MAXN];
int f[MAXN], n, k;

int dfs(int a, int b) {
    if (dp[a][b]) return 0;
    dp[a][b] = 1;
    int cnt = 1;
    for (int i = 0; i < (int)G[a][b].size(); ++ i) {
        int x = G[a][b][i].first, y = G[a][b][i].second;
        cnt += dfs(x, y);
    }
    return cnt;
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                dp[i][j] = 0;
                G[i][j].clear();
            }
        }
        for (int _ = 0; _ < k; ++ _) {
            for (int i = 0; i < n; ++ i) scanf("%d", f + i);
            for (int i = 0; i < n; ++ i) {
                for (int j = 0; j < n; ++ j) {
                    G[f[i]][f[j]].push_back(PII(i, j));
                }
            }
        }
        int ret = dfs(0, 0);
        if (ret == n * n) puts("TAK");
        else puts("NIE");
    }
    return 0;
}
