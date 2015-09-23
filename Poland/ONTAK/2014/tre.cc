#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
char mp[MAXN][MAXN];
int vis[MAXN][MAXN], dp[MAXN][MAXN];
int n, m, sz;

PII get(int s, int t) {
    PII a = PII(s + 1, t), b = PII(s, t + 1); ++ sz;
    while (a != b) {
        if (mp[a.first][a.second] == 'M' || mp[a.first][a.second] == 'O') a.second ++;
        else a.first ++;
        if (vis[a.first][a.second] == sz) return a;
        vis[a.first][a.second] = sz;
        if (mp[b.first][b.second] == 'R' || mp[b.first][b.second] == 'O') b.first ++;
        else b.second ++;
        if (vis[b.first][b.second] == sz) return b;
        vis[b.first][b.second] = sz;
    }
    return a;
}

int main() {
    scanf("%d%d", &m, &n); sz = 0;
    for (int i = 1; i <= n; ++ i) scanf("%s", mp[i] + 1);
    for (int i = n; i >= 1; -- i) {
        for (int j = m; j >= 1; -- j) {
            if (mp[i][j] == 'X') dp[i][j] = 1;
            else if (mp[i][j] == 'R') dp[i][j] = dp[i + 1][j] + 1;
            else if (mp[i][j] == 'M') dp[i][j] = dp[i][j + 1] + 1;
            else {
                PII now = get(i, j);
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[now.first][now.second] + 1;
            }
        }
    }
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            printf("%d%c", dp[i][j], " \n"[j == m]);
        }
    }
    return 0;
}
