#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 260, SZ = 5200, MOD = 1e7;
const int pl[6] = {2, 3, 5, 7, 11, 13};

int idx[8][6][4][3][3][3], val[SZ];
int ggcd[MAXN][MAXN], remain[MAXN];
vector<int> st[MAXN], Map[SZ];
int dp[3][SZ][MAXN], vis[SZ];

inline int get(vector<int> &v) {
  return idx[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]];
}

LL pw(int a, int b) {
  int r(1);
  for (int i = 0; i < b; ++ i) r *= a;
  return r;
}
void init() {
  for (int i = 0; i < MAXN; ++ i) {
    for (int j = 0; j < MAXN; ++ j) {
      ggcd[i][j] = __gcd(i, j);
    }
  }
  int sz = 0;
  for (int a = 0; a < 8; ++ a) for (int b = 0; b < 6; ++ b) for (int c = 0; c < 4; ++ c) {
    for (int d = 0; d < 3; ++ d) for (int e = 0; e < 3; ++ e) for (int f = 0; f < 3; ++ f) {
      val[sz] = pw(2, a) * pw(3, b) * pw(5, c) * pw(7, d) * pw(11, e) * pw(13, f) % MOD;
      Map[sz] = {a, b, c, d, e, f};
      idx[a][b][c][d][e][f] = sz ++;
    }
  }
  for (int i = 1; i < MAXN; ++ i) {
    vector<int> &pt = st[i]; remain[i] = i;
    int &t = remain[i];
    for (int j = 0; j < 6; ++ j) {
      int c(0);
      while (t % pl[j] == 0) t /= pl[j], ++ c;
      pt.push_back(c);
    }
  }
}

PII A[MAXN];

int  solve(vector<int> &v, int mul) {
  int curr = 2;
  vector<int> pt(6, 0);
  for (size_t i = 0; i < v.size(); ++ i) {
    int cut = v[i], org = cut * mul;
    int prev = ((curr - 1) ^ 1) + 1;
    for (int j = 0; j < SZ; ++ j) if (vis[j]) {
      for (int k = 0; k < MAXN; ++ k) {
        dp[curr][j][k] = dp[prev][j][k];
      }
    }
    for (int j = 0; j < SZ; ++ j) if (vis[j]) {
      for (int l = 0; l < 6; ++ l) {
        pt[l] = max(Map[j][l], st[cut][l]);
      }
      int new_lcm = get(pt);
      for (int k = 0; k < MAXN; ++ k) if (dp[prev][j][k]) {
        int new_gcd = ggcd[k][org];
        dp[curr][new_lcm][new_gcd] += dp[prev][j][k];
        vis[new_lcm] = 1; dp[curr][new_lcm][new_gcd] %= MOD;
      }
    }
    curr = ((curr - 1) ^ 1) + 1;
  }
  return ((curr - 1) ^ 1) + 1;
}

int main() {
  init();
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      A[i].first = remain[x];
      A[i].second = x / remain[x];
    }
    sort(A, A + n); A[n].first = -1;
    vector<int> mul, pt;
    vector<vector<int> > block;
    for (int i = 0; i < n; ++ i) {
      pt.push_back(A[i].second);
      if (A[i].first != A[i + 1].first) {
        block.push_back(pt); pt.clear();
        mul.push_back(A[i].first);
      }
    }
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[1][0][0] = dp[0][0][0] = vis[0] = 1;
    for (size_t i = 0; i < block.size(); ++ i) {
      int tmp = solve(block[i], mul[i]);
      for (int j = 0; j < SZ; ++ j) if (vis[j]) {
        for (int k = 0; k < MAXN; ++ k) {
          dp[0][j][k] += LL(dp[tmp][j][k] - dp[0][j][k]) * mul[i] % MOD;
          dp[0][j][k] %= MOD; dp[0][j][k] += MOD; dp[0][j][k] %= MOD;
          dp[1][j][k] = dp[0][j][k];
        }
      }
    }
    LL ret(0);
    for (int i = 0; i < SZ; ++ i) if (vis[i]) {
      for (int j = 1; j < MAXN; ++ j) {
        ret += (LL)val[i] * j * dp[0][i][j] % MOD;
      }
    }
    printf("%lld\n", ret % MOD);
  }
  return 0;
}

