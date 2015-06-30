#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100 + 10, MOD = 1e9 + 7;
vector<int> G[MAXN];
LL dp[MAXN], fac[MAXN], inv[MAXN];
int n, s, f;

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

LL C(int n, int m) {
  return fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

LL solve(vector<LL> v) {
  static LL dp[MAXN][MAXN];
  int n = v.size();
  for (int i = 0; i <= n; ++ i) {
    for (int j = 0; j <= n; ++ j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 0; j <= n; ++ j) dp[i][j] = dp[i - 1][j];
    for (int j = 0; j <= n; ++ j) {
      if (j) dp[i][j] += dp[i - 1][j - 1] * v[i - 1] % MOD;
    }
    for (int j = 0; j <= n; ++ j) dp[i][j] %= MOD;
  }
  LL r(0);
  for (int i = 0; i <= n; ++ i) r += dp[n][i] * fac[i] % MOD;
  return r % MOD;
}

bool dfs(int u, int p = -1) {
  dp[u] = 1;
  if (u == f) return 1;
  vector<LL> pt;
  bool has(0);
  LL cf;
  for (auto &v: G[u]) if (v != p) {
    if (dfs(v, u)) has = 1, cf = dp[v];
    else pt.push_back(dp[v]);
  }
  if (!has) {
    for (auto &x: pt) dp[u] = dp[u] * x % MOD;
    dp[u] = dp[u] * fac[pt.size()] % MOD;
  }
  else {
    dp[u] = cf * solve(pt) % MOD;
  }
  return has;
}

int main() {
  fac[0] = 1; inv[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = pm(fac[i], MOD - 2);
  }
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    cin >> n >> s >> f;
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v; cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    dfs(s);
    printf("%lld\n", dp[s]);
  }
  return 0;
}

