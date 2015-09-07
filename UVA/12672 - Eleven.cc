#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7, MAXN = 100 + 10;

int dp[10][MAXN][11][11], C[MAXN][MAXN], d[10];

int solve(int p, int even, int odd, int em, int om) {
    if (p == 10) return em == om;
    if (dp[p][even][em][om] != -1) return dp[p][even][em][om];
    int &ret = dp[p][even][em][om]; ret = 0;
    for (int i = 0; i <= d[p]; ++ i) {
        if (i > odd || d[p] - i > even) continue;
        int tmp = (LL)C[odd][i] * C[even][d[p] - i] % MOD;
        ret += (LL)tmp * solve(p + 1, even - (d[p] - i), odd - i, (em + (d[p] - i) * p) % 11, (om + i * p) % 11) % MOD;
        ret %= MOD;
    }
    return ret;
}

int main() {
    char N[110];
    for (int i = 0; i < MAXN; ++ i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    while (scanf("%s", N) == 1) {
        memset(d, 0, sizeof(d));
        int len = strlen(N), odd = (len + 1) / 2, even = len - odd;
        for (int i = 0; i < len; ++ i) ++ d[N[i] - '0'];
        memset(dp, -1, sizeof(dp));
        int ret = 0;
        for (int i = 0; i <= d[0]; ++ i) {
            if (i > odd - 1) continue;
            int tmp = (LL)C[odd - 1][i] * C[even][d[0] - i] % MOD;
            ret += (LL)tmp * solve(1, even - (d[0] - i), odd - i, 0, 0) % MOD;
            ret %= MOD;
        }
        printf("%d\n", ret);
    }
}
