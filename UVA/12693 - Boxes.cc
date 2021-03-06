#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 10, MAXW = 1000 + 10, MOD = 10007;

int dp[MAXN][MAXN][MAXW], C[MAXN][MAXN];
int cnt[MAXW], A[MAXN], B[MAXN];
int N, M, W;

int main() {
    for (int i = 0; i < MAXN; ++ i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d%d", &N, &W); M = 0;
        for (int i = 0; i <= W; ++ i) cnt[i] = 0;
        for (int i = 0; i < N; ++ i) {
            int x; scanf("%d", &x);
            ++ cnt[x];
        }
        for (int i = W; i >= 0; -- i) {
            if (!cnt[i]) continue;
            A[++ M] = i; B[M] = cnt[i];
        }
        for (int i = 0; i <= M; ++ i) {
            for (int j = 0; j <= N; ++ j) {
                for (int k = 0; k <= W; ++ k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for (int i = 1; i <= M; ++ i) {
            for (int j = 0; j <= N; ++ j) {
                for (int k = 0; k <= W; ++ k) {
                    if (dp[i - 1][j][k] == 0) continue;
                    for (int x = 0; x <= B[i]; ++ x) {
                        if (k + x * A[i] > W) break;
                        dp[i][j + x][k + x * A[i]] += dp[i - 1][j][k] * C[j + x][x] % MOD;
                        dp[i][j + x][k + x * A[i]] %= MOD;
                    }
                }
            }
        }
        int ret = 0;
        for (int now = 1; now <= W; ++ now) {
            int gap = W - now, used = 0, st = 0;
            for (int i = M; i > 0; -- i) {
                if (A[i] <= gap) {
                    used += A[i] * B[i];
                }
                else {
                    st = i;
                    break;
                }
            }
            if (used > now) continue;
            for (int k = 0; k <= N; ++ k) {
                if (dp[st][k][now - used] == 0) continue;
                int tmp = dp[st][k][now - used], tot = k;
                for (int i = M; i > 0; -- i) {
                    if (A[i] <= gap) {
                        tmp = tmp * C[tot + B[i]][B[i]] % MOD;
                        tot += B[i];
                    }
                }
                ret = (ret + tmp) % MOD;
            }
        }
        printf("Case %d: %d\n", cas, ret);
    }
    return 0;
}
