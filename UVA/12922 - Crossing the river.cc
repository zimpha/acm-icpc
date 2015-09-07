#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dp[1 << 16], popcount[1 << 16], n, k;
int sw[1 << 16], w[16], W;

int solve(int msk) {
  if (dp[msk] != -1) return dp[msk];
  int &ret = dp[msk]; ret = 1e9;
  if (popcount[msk] <= k && sw[msk] <= W) return dp[msk] = 1;
  for (int sub = (msk - 1) & msk; sub; sub = (sub - 1) & msk) {
    if (popcount[sub] > k || sw[sub] > W) continue;
    int r(-1), rst = ((1 << n) - 1) ^ (msk ^ sub);
    for (int i = 0; i < n; ++ i) if (rst >> i & 1) {
      if (r == -1 || w[i] < w[r]) r = i;
    }
    int nxt = (msk ^ sub) | (1 << r);
    ret = min(ret, solve(nxt) + 2);
  }
  return dp[msk] = ret;
}

int main() {
  while (scanf("%d%d%d", &n, &W, &k) == 3) {
    for (int i = 0; i < n; ++ i) scanf("%d", w + i);
    for (int msk = 0; msk < (1 << n); ++ msk) {
      popcount[msk] = sw[msk] = 0; dp[msk] = -1;
      for (int i = 0; i < n; ++ i) {
        if (msk >> i & 1) {
          sw[msk] += w[i];
          popcount[msk] ++;
        }
      }
    }
    int ret = solve((1 << n) - 1);
    if (ret == 1e9) ret = -1;
    printf("%d\n", ret);
  }
  return 0;
}
