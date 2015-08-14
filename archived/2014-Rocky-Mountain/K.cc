#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void print(LL a, LL b) {
  if (b < 0) b *= -1, a *= -1;
  LL g = __gcd(abs(a), abs(b));
  a /= g; b /= g;
  if (a % b == 0) printf("%lld\n", a / b);
  else {
    LL t = a / b;
    if (a < 0) -- t;
    printf("%lld ", t);
    a -= t * b;
    print(b, a);
  }
}

int main() {
  int n, m, a[100], cas(0);
  while (scanf("%d%d", &n, &m) == 2 && n + m) {
    for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    reverse(a, a + n);
    LL p(1), q(a[0]);
    for (int i = 1; i < n; ++ i) {
      p += a[i] * q;
      swap(p, q);
      if (q < 0) q *= -1, p *= -1;
      LL g = __gcd(abs(p), abs(q));
      p /= g; q /= g;
    }
    swap(p, q);
    if (q < 0) q *= -1, p *= -1;
    for (int i = 0; i < m; ++ i) scanf("%d", a + i);
    reverse(a, a + m);
    LL r(1), s(a[0]);
    for (int i = 1; i < m; ++ i) {
      r += a[i] * s;
      swap(r, s);
      if (s < 0) s *= -1, r *= -1;
      LL g = __gcd(abs(r), abs(s));
      r /= g; s /= g;
    }
    swap(r, s);
    if (s < 0) s *= -1, r *= -1;
    printf("Case %d:\n", ++ cas);
    print(p * s + q * r, q * s);
    print(p * s - q * r, q * s);
    print(p * r, q * s);
    print(p * s, q * r);
  }
  return 0;
}

