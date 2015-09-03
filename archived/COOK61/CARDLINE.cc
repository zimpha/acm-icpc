#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;

int dp[MAXN][MAXN];
int a[MAXN], b[MAXN], vs[MAXN];

int main() {
  for (int l = 1; l < MAXN; ++ l) {
    for (int i = l; i < MAXN; ++ i) {
      dp[l][i] = l - 1 + dp[l][i - l];
      if (i >= l + 1) dp[l][i] = max(dp[l][i], l + dp[l][i - l - 1]);
    }
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) vs[i] = 0;
    for (int i = 1; i <= n; ++ i) {
      int x; scanf("%d", &x);
      a[i] = x;
    }
    for (int i = 1; i <= n; ++ i) {
      int x; scanf("%d", &x);
      b[x] = i;
    }
    vector<int> circle;
    int ret(0);
    for (int i = 1; i <= n; ++ i) if (!vs[i]) {
      int c(0);
      for (int p = i; !vs[p]; p = b[a[p]]) vs[p] = 1, ++ c;
      circle.push_back(c);
      ret += c == 1;
    }
    for (int len = 1; len <= n; ++ len) {
      int tmp(0);
      for (auto &x: circle) tmp += dp[len][x];
      ret = max(ret, tmp);
    }
    printf("%d\n", ret);
  }
  return 0;
}
