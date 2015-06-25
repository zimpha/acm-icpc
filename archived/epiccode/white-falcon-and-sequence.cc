#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 3000 + 10;
LL dp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int A[MAXN], n;

LL solve(int l, int r) {
  if (l >= r) return 0;
  if (vis[l][r]) return dp[l][r];
  vis[l][r] = 1;
  dp[l][r] = max(0ll, solve(l + 1, r - 1) + (LL)A[l] * A[r]);
  return dp[l][r];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", A + i);
  LL ret(0);
  for (int i = 0; i < n; ++ i) {
    for (int j = i + 1; j < n; ++ j) {
      ret = max(ret, solve(i, j));
    }
  }
  printf("%lld\n", ret);
}