#include <bits/stdc++.h>
using namespace std;

char name[10000];

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int MAXN = 1000;

int A[MAXN][MAXN], dp[MAXN][MAXN];
int N, M;

int solve(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; ++ i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
        if (A[xx][yy] < A[x][y]) {
            dp[x][y] = max(dp[x][y], solve(xx, yy) + 1);
        }
    }
    return dp[x][y];
}

int main() {
    int T; scanf("%d", &T);
    while (T --) {
        scanf("%s%d%d", name, &N, &M);
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < M; ++ j) {
                dp[i][j] = 0;
                scanf("%d", &A[i][j]);
            }
        }
        int ret = 0;
        for (int i = 0; i < N; ++ i) {
            for (int j = 0; j < M; ++ j) {
                ret = max(ret, solve(i, j));
            }
        }
        printf("%s: %d\n", name, ret);
    }
    return 0;
}
