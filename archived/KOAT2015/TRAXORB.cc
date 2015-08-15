#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10, P = 1e9 + 7;
LL fac[MAXN], inv[MAXN];
LL pw(LL a, LL n, LL r=1) {
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % P;
    a = a * a % P;
  }
  return r;
}
LL NCR(LL n, LL r) {
  if (n >= r) return fac[n] * inv[r] % P * inv[n - r] % P;
  else return 0;
}

int main() {
  fac[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    fac[i] = fac[i - 1] * i % P;
    inv[i] = pw(fac[i], P - 2);
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N, R, K; scanf("%d%d%d", &N, &R, &K);
    LL y = N / R, ret = 0;
    for (int i = 0; i <= R; ++ i) {
      if (i & 1) ret -= NCR(R, i) * NCR(N - i * y, K) % P;
      else ret += NCR(R, i) * NCR(N - i * y, K) % P;
    }
    ret %= P; ret += P; ret %= P;
    cout << ret << endl;
  }
  return 0;
}
