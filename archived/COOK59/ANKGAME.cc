#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10, MOD = 1e9 + 7;
LL f[MAXN], g[MAXN];

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int main() {
  f[0] = g[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    f[i] = f[i - 1] * i % MOD;
    g[i] = pm(f[i], MOD - 2);
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N; scanf("%d", &N);
    map<LL, int> mp;
    for (int i = 0; i < N; ++ i) {
      LL x; scanf("%lld", &x);
      mp[x] ++;
    }
    LL K(1), M(0);
    for (auto &x: mp) {
      if (x.first != 1) K = K * g[x.second] % MOD;
      else M = x.second;
    }
    if (M == N) printf("%d\n", N & 1);
    else {
      LL ret(0);
      for (int r = 0; r * 2 <= M; ++ r) {
        ret += K * f[N - r * 2] % MOD * g[M - r * 2] % MOD;;
        if (r * 2 + 1 <= M) {
          ret -= K * f[N - r * 2 - 1] % MOD * g[M - r * 2 - 1] % MOD;
        }
      }
      ret %= MOD; ret += MOD; ret %= MOD;
      printf("%lld\n", ret);
    }
  }
  return 0;
}

