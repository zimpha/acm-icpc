#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
VI operator + (const VI &A, const VI &B) {
    int M = 1e9, c = 0;
    VI C; C.resize(max(A.size(), B.size()), 0);
    for (int i = 0; i < (int)A.size() || i < (int)B.size(); ++ i) {
        int a = 0, b = 0;
        if (i < (int)A.size()) a = A[i];
        if (i < (int)B.size()) b = B[i];
        C[i] = a + b + c;
        c = C[i] / M;
        C[i] %= M;
    }
    if (c) C.push_back(c);
    return C;
}

void print(VI A) {
    printf("%d", A.back());
    for (A.pop_back(); !A.empty(); A.pop_back()) {
        printf("%0*d", 9, A.back());
    }
    puts("");
}

const int MAXN = 1000 + 10;
VI dp[2][MAXN];
int g[2][MAXN], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; ++ i) {
        for (int j = 1; j <= n; ++ j) {
            scanf("%d", &g[i][j]);
        }
    }
    int lim = 0;
    for (int i = 1; i <= n; ++ i) {
        if (g[0][i] == i || g[0][i] == 0) lim = i;
        else break;
    }
    dp[0][0].push_back(1);
    for (int i = 1, t = 1; i <= n; ++ i, t ^= 1) {
        dp[t][0].clear(); dp[t][0].push_back(lim >= i);
        for (int j = 1; j <= i; ++ j) {
            dp[t][j].clear(); dp[t][j].push_back(0);
            if (g[0][i] == 0 || g[0][i] == i + j) dp[t][j] = dp[t][j] + dp[t ^ 1][j];
            if (g[1][j] == 0 || g[1][j] == i + j) dp[t][j] = dp[t][j] + dp[t][j - 1];
        }
    }
    print(dp[n & 1][n]);
    return 0;
}
