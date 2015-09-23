#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 3100;
char mp[MAXN][MAXN];
PII R[MAXN][MAXN], D[MAXN][MAXN];
int vis[MAXN][MAXN], dp[MAXN][MAXN];
int n, m, P;

inline PII get(int s, int t) {
    PII a = PII(s + 1, t), b = PII(s, t + 1);
    while (a != b) {
        PII na = R[a.x][a.y], nb = D[b.x][b.y];
        if (na.x > nb.x && na.y < nb.y) {
            a = na, b = nb;
            continue;
        }
        if (mp[a.x][a.y] == 'O' || mp[a.x][a.y] == 'M') ++ a.y;
        else ++ a.x;
        if (mp[b.x][b.y] == 'O' || mp[b.x][b.y] == 'R') ++ b.x;
        else ++ b.y;
    }
    return a;
}

inline void gaoR(int a, int b) {
    int sx = a, sy = b;
    for (int _ = 0; _ < P; ++ _) {
        if (mp[a][b] == 'O' || mp[a][b] == 'M') ++ b;
        else ++ a;
    }
    if (a > n || b > m) a = n, b = m;
    R[sx][sy] = PII(a, b);
}

inline void gaoD(int a, int b) {
    int sx = a, sy = b;
    for (int _ = 0; _ < P; ++ _) {
        if (mp[a][b] == 'O' || mp[a][b] == 'R') ++ a;
        else ++ b;
    }
    if (a > n || b > m) a = n, b = m;
    D[sx][sy] = PII(a, b);
}

int main() {
    scanf("%d%d", &m, &n); P = 10;
    while (P * P * P * (P + 10) < n * m) ++ P;
    for (int i = 1; i <= n; ++ i) scanf("%s", mp[i] + 1);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            gaoR(i, j);
            gaoD(i, j);
        }
    }
    for (int i = n; i >= 1; -- i) {
        for (int j = m; j >= 1; -- j) {
            if (mp[i][j] == 'X') dp[i][j] = 1;
            else if (mp[i][j] == 'R') dp[i][j] = dp[i + 1][j] + 1;
            else if (mp[i][j] == 'M') dp[i][j] = dp[i][j + 1] + 1;
            else {
                PII now = get(i, j);
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1] - dp[now.x][now.y] + 1;
            }
        }
    }
    ios::sync_with_stdio(false);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
