#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 5000 + 10;

LL dp[MAXN];
int V[MAXN], C[MAXN];
int N, S;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d%d", &S, &N);
    for (int i = 0; i < N; ++ i) {
      scanf("%d%d", V + i, C + i);
    }
    LL ret(0);
    for (int cnt = 1; cnt <= S; ++ cnt) if (S % cnt == 0) {
      int m = S / cnt; dp[0] = 1;
      for (int i = 1; i <= m; ++ i) dp[i] = 0;
      for (int i = 0; i < N; ++ i) if (C[i] >= cnt) {
        for (int j = m; j >= V[i]; -- j) {
          dp[j] += dp[j - V[i]];
        }
      }
      ret += dp[m];
    }
    printf("Case %d: %lld\n", cas, ret);
  }
  return 0;
}

