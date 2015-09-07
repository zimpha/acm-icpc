#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000 + 10;
vector<int> pp[MAXN];
int vis[MAXN], cnt[MAXN], N, cas;
double dp[MAXN];

double solve(int n) {
    if (n == 1) return 0.0;
    if (vis[n]) return dp[n];
    vis[n] = 1; dp[n] = 0;
    for (int i = 0; i < (int)pp[n].size(); ++ i) {
        dp[n] += solve(n / pp[n][i]);
    }
    dp[n] = (dp[n] + cnt[n]) / pp[n].size();
    return dp[n];
}

int main() {
    for (int i = 2; i < MAXN; ++ i) {
        if (pp[i].empty()) {
            cnt[i] = 1;
            for (int j = i; j < MAXN; j += i) {
                pp[j].push_back(i);
            }
        }
    }
    for (int i = 2; i < MAXN; ++ i) cnt[i] += cnt[i - 1];
    int T; scanf("%d", &T);
    for (cas = 1; cas <= T; ++ cas) {
        scanf("%d", &N);
        printf("Case %d: %.10f\n", cas, solve(N));
    }
    return 0;
}
