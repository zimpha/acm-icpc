#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 400000 + 10, MOD = 530600414;

LL cnt[MAXN], sz[MAXN], len[MAXN], f[MAXN];

int main() {
  cnt[3] = 1; cnt[4] = 1;
  sz[3] = 1; sz[4] = 3;
  len[3] = 3; len[4] = 5;
  f[3] = f[4] = 0;
  for (int n = 5; n < MAXN; ++ n) {
    f[n] = (f[n - 1] + f[n - 2]) % MOD;
    f[n] += cnt[n - 2] * cnt[n - 1] % MOD * len[n - 2] % MOD;
    f[n] += cnt[n - 2] * sz[n - 1] % MOD;
    f[n] -= sz[n - 2] * cnt[n - 1] % MOD;
    f[n] %= MOD; if (f[n] < 0) f[n] += MOD;
    len[n] = (len[n - 1] + len[n - 2]) % MOD;
    cnt[n] = (cnt[n - 1] + cnt[n - 2]) % MOD;
    sz[n] = (sz[n - 1] + sz[n - 2] + cnt[n - 1] * len[n - 2]) % MOD;
  }
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n; scanf("%d", &n);
    printf("Case #%d: %lld\n", cas, f[n]);
  }
  return 0;
}