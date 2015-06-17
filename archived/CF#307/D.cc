#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL pm(LL a, LL n, LL m) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % m;
    a = a * a % m;
  }
  return r;
}
//f[0] = 0, f[1] = 1
PII fib(LL n, LL m) {
  if (n <= 2) return PII(!!n%m,n/2%m);
  PII t=fib(n/2+1,m);
  int x=t.first, y=t.second;
  int p=(LL(x) * x + LL(y) * y) % m;
  int q = (x * 2ll * y % m - LL(y) * y % m + m) % m;
  if (n & 1) return PII(p, q);;
  return PII(q,(p-q+m)%m);
}

int main() {
  LL n, k, l, m; cin >> n >> k >> l >> m;
  if (m == 1 || (l < 63 && (1ll << l) <= k)) {
    puts("0"); return 0;
  }
  if (l == 0) {
    if (k == 0) puts("1");
    else puts("0");
    return 0;
  }
  LL pw = pm(2, n, m);
  LL f = fib(n + 2, m).first;
  LL r(1);
  for (int i = 0; i < l; ++ i) {
    if (k >> i & 1) r = r * (pw - f + m) % m;
    else r = r * f % m;
  }
  cout << r << endl;
  return 0;
}

