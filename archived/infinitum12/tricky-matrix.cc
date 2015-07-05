#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int MAXN = 3000 + 10;

LL X[MAXN], Y[MAXN];
int N;

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++ i) scanf("%lld", X + i);
    for (int i = 1; i <= N; ++ i) {
      scanf("%lld", Y + i);
      Y[i] = MOD - Y[i];
    }
    LL P(1), Q(1);
    for (int i = 2; i <= N; ++ i) {
      for (int j = 1; j <= i - 1; ++ j) {
        P = P * (X[i] - X[j] + MOD) % MOD * (Y[j] - Y[i] + MOD) % MOD;
      }
    }
    for (int i = 1; i <= N; ++ i) {
      for (int j = 1; j <= N; ++ j) {
        Q = Q * (X[i] - Y[j] + MOD) % MOD;
      }
    }
    printf("%lld\n", P * pm(Q, MOD - 2) % MOD);
  }
  return 0;
}

