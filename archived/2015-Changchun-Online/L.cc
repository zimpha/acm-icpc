#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10, MOD = 1e9 + 7;

LL pw[MAXN];
int x[MAXN], y[MAXN], n;

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return 2;
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < MAXN; ++ i) pw[i] = pw[i - 1] * 2 % MOD;
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d%d", x + i, y + i);
    LL sx(0), sy(0), ret(0);
    LL tx(0), ty(0);
    for (int i = 1; i < n; ++ i) {
      sx += x[i] * pw[n - 1 - i] % MOD;
      tx += x[i]; ty += y[i];
      if (sx >= MOD) sx -= MOD;
      sy += y[i] * pw[n - 1 - i] % MOD;
      if (sy >= MOD) sy -= MOD;
    }
    ty %= MOD; tx %= MOD;
    if (tx < 0) tx += MOD;
    if (ty < 0) ty += MOD;
    for (int i = 0; i < n; ++ i) {
      ret += (x[i] * (sy - ty) - y[i] * (sx - tx)) % MOD;
      int j = (i + 1) % MOD;
      sx -= x[j] * pw[n - 2] % MOD;
      sy -= y[j] * pw[n - 2] % MOD;
      tx -= x[j]; ty -= y[j];
      sx *= 2; sy *= 2;
      sx += x[i]; sy += y[i];
      tx += x[i]; ty += y[i];
      sx %= MOD; sy %= MOD;
      if (sx < 0) sx += MOD;
      if (sy < 0) sy += MOD;
      tx %= MOD; ty %= MOD;
      if (tx < 0) tx += MOD;
      if (ty < 0) ty += MOD;
    }
    ret %= MOD; ret = (ret + MOD) % MOD;
    printf("%lld\n", ret);
  }
  return 0;
}

