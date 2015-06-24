#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL dp[20][2][2], pw[20];
char A[30], B[30];

LL solve(int n, int ea, int eb) {
  if (n == 20) return 0;
  if (dp[n][ea][eb] != -1) return dp[n][ea][eb];
  int da = ea ? A[n] - '0' : 9;
  int db = eb ? B[n] - '0' : 9;
  for (int a = 0; a <= da; ++ a) {
    for (int b = 0; b <= db; ++ b) {
      int c = (a + b) % 10;
      dp[n][ea][eb] = max(dp[n][ea][eb], pw[19 - n] * c + solve(n + 1, ea & (a == da), eb & (b == db)));
    }
  }
  return dp[n][ea][eb];
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < 20; ++ i) pw[i] = pw[i - 1] * 10;
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    LL n, m; cin >> n >> m;
    sprintf(A, "%020lld", n);
    sprintf(B, "%020lld", m);
    memset(dp, -1, sizeof(dp));
    printf("%lld\n", solve(0, 1, 1));
  }
  return 0;
}

