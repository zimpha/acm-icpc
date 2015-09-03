#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int dp[20][1 << 16], trans[20][1 << 16];
int a[20], n, k, L;

int get(int v, int msk) {
  int lcs[2][20], ret(0);
  lcs[0][0] = lcs[1][0] = 0;
  for (int i = 0, l = 0; i < n; ++ i) {
    if (msk >> i & 1) ++ l;
    lcs[0][i + 1] = l;
  }
  for (int i = 1; i <= n; ++ i) {
    lcs[1][i] = (v == a[i - 1]) ? 1 + lcs[0][i - 1] : max(lcs[0][i], lcs[1][i - 1]);
    if (lcs[1][i] > lcs[1][i - 1]) ret |= 1 << (i - 1);
  }
  return ret;
}

int solve(int b, int msk) {
  int ret(0);
  if (b == n) return __builtin_popcount(msk) == L;
  if (dp[b][msk] != -1) return dp[b][msk];
  for (int i = 0; i < k; ++ i) {
    ret += solve(b + 1, trans[i][msk]);
    if (ret >= MOD) ret -= MOD;
  }
  return dp[b][msk] = ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d", &n, &k, &L);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", a + i); -- a[i];
    }
    for (int i = 0; i < k; ++ i) {
      for (int msk = 0; msk < (1 << n); ++ msk) {
        trans[i][msk] = get(i, msk);
      }
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, 0));
  }
  return 0;
}

