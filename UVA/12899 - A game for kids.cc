#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10, MOD = 21092013;

vector<int> G[MAXN];
int L[MAXN], H[MAXN], cnt[MAXN];
int ans[60], n, rt, tot, mins;

LL dp[MAXN][2];
void dfs(int u, int f = -1) {
  dp[u][0] = 0; dp[u][1] = cnt[u];
  LL s(0);
  for (auto &v: G[u]) if (v != f) {
    dfs(v, u);
    dp[u][1] += dp[v][1] * cnt[u];
    dp[u][0] += dp[v][1] + dp[v][0];
    dp[u][0] += dp[v][1] * cnt[u] % MOD * s % MOD;
    s += dp[v][1]; if (s >= MOD) s -= MOD;
  }
  dp[u][0] %= MOD; dp[u][1] %= MOD;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++ i) scanf("%d", L + i);
    for (int i = 1; i <= n; ++ i) scanf("%d", H + i);
    for (int g = 50; g >= 1; -- g) {
      for (int i = 1; i <= n; ++ i) {
        cnt[i] = H[i] / g - (L[i] - 1) / g;
      }
      dfs(1);
      ans[g] = dp[1][0] + dp[1][1];
      for (int i = g * 2; i <= 50; i += g) {
        ans[g] -= ans[i];
      }
      ans[g] %= MOD;
      if (ans[g] < 0) ans[g] += MOD;
    }
    printf("Case %d:\n", cas);
    for (int i = 1; i <= 50; ++ i) {
      printf("%d: %d\n", i, ans[i]);
    }
  }
  return 0;
}