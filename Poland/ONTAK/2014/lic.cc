#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100 + 10;
int dp[32][MAXN], G[32][MAXN][MAXN];
int F[32][MAXN], C[MAXN][MAXN];
int cnt[32], n, p, m;

LL pm(LL a, LL n) { 
    LL r = 1;
    for (; n; n >>= 1, a = a * a % p) {
        if (n & 1) r = r * a % p;
    }
    return r;
}

void calcG(int l, int g[MAXN][MAXN]) {
    g[0][0] = 1;
    for (int i = 1, mx = (l + 1) / 2; i <= m; ++ i) {
        for (int j = i; j <= m; ++ j) {
            g[i][j] = 0;
            for (int k = 1; j - k >= i - 1 && k <= mx; ++ k) {
                g[i][j] += (LL)g[i - 1][j - k] * C[l - k + 1][k] % p;
                g[i][j] %= p;
            }
        }
    }
}

void comb(int id, int m) {
    map<int, int> mp;
    map<int, int>::iterator it;
    F[id][0] = 1;
    for (int i = 0; i < m; ++ i) {
        int x = cnt[id] - i;
        for (int y = 2, s = sqrt(x + 10); y <= s; ++ y) {
            while (x % y == 0) x /= y, mp[y] ++;
            s = sqrt(x + 10);
        }
        if (x > 1) mp[x] ++;
        x = i + 1;
        for (int y = 2, s = sqrt(x + 10); y <= s; ++ y) {
            while (x % y == 0) x /= y, mp[y] --;
            s = sqrt(x + 10);
        }
        if (x > 1) mp[x] --;
        LL ret = 1;
        for (it = mp.begin(); it != mp.end(); ++ it) {
            ret = ret * pm(it->first, it->second) % p;
        }
        F[id][i + 1] = ret;
    }
}

int count(int n) {
    return (n + 1) >> 1;
}

int main() {
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i <= 100; ++ i) {
        C[i][0] = C[i][i] = 1 % p;
        for (int j = 1; j < i; ++ j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
        }
    }
    memset(G, 0, sizeof(G));
    for (int i = 1; i < 32; ++ i) calcG(i, G[i - 1]);
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; (1 << i) <= n; ++ i) {
        cnt[i] = count(n / (1 << i)) - count(n / (1 << (i + 1)));
    }
    for (int i = 0; i < 32; ++ i) comb(i, min(m, cnt[i]));
    memset(dp, 0, sizeof(0)); dp[0][0] = 1;
    for (int i = 0; i < 31; ++ i) {
        for (int j = 0; j <= m; ++ j) {
            int &ret = dp[i + 1][j];
            for (int k = 0; k <= j; ++ k) {
                for (int l = 0; l <= min(k, cnt[i]); ++ l) {
                    ret += (LL)dp[i][j - k] * F[i][l] % p * G[i][l][k] % p;
                    ret %= p;
                }
            }
        }
    }
    printf("%d\n", dp[31][m]);
    return 0;
}
