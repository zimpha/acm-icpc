#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;

struct Complex {
  flt x, y;
  Complex() {}
  Complex(flt x, flt y): x(x), y(y) {}
  Complex operator + (const Complex &r) const {
    return Complex(x + r.x, y + r.y);
  }
  Complex operator - (const Complex &r) const {
    return Complex(x - r.x, y - r.y);
  }
  Complex operator * (const Complex &r) const {
    return Complex(x * r.x - y * r.y, x * r.y + y * r.x);
  }
  Complex& operator /= (const flt &r) {
    x /= r; y /= r; return *this;
  }
};

const int W = 1 << 15;
const flt PI = acos(-1.0);
Complex pw[W], ipw[W];

void fft(Complex *f, int n, bool inv) {
  for (int i = 1, j = 0; i < n; ++ i) {
    int bit = n >> 1;
    while (j >= bit) j -= bit, bit >>= 1;
    j += bit; if (i < j) swap(f[i], f[j]);
  }
  for (int len = 2, s = W >> 1; len <= n; len <<= 1, s >>= 1) {
    int len2 = len >> 1;
    for (int i = 0; i < n; i += len) {
      for (int j = 0; j < len2; ++ j) {
        Complex u = f[i + j];
        Complex v = f[i + j + len2] * (inv ? ipw[j * s] : pw[j * s]);
        f[i + j] = u + v; f[i + j + len2] = u - v;
      }
    }
  }
  if (inv) {
    for (int i = 0; i < n; ++ i) f[i] /= n;
  }
}

const int MAXN = 8000 + 10;

int a[MAXN], b[MAXN], ret[MAXN], n, MOD;

void solve(int l, int r) {
  if (l + 1 == r) {
    ret[1] += (a[l] == 0) + (b[l] == 0);
    ret[1] %= MOD;
    return;
  }
  static Complex u[W], v[W];
  static int L[MAXN][64], R[MAXN][64];
  int m = (l + r) >> 1, n1 = m - l, n2 = r - m;
  solve(l, m); solve(m, r);
  int s = 1; while (s <= n1 + n2) s <<= 1;
  memset(L[0], 0, sizeof(L[0])); L[0][0] = 1;
  for (int i = m - 1; i >= l; -- i) {
    int x = m - i;
    for (int j = 0; j < 64; ++ j) {
      L[x][j] = L[x - 1][j ^ a[i]] + L[x - 1][j ^ b[i]];
      if (L[x][j] >= MOD) L[x][j] -= MOD;
    }
  }
  memset(R[0], 0, sizeof(R[0])); R[0][0] = 1;
  for (int i = m; i < r; ++ i) {
    int x = i - m + 1;
    for (int j = 0; j < 64; ++ j) {
      R[x][j] = R[x - 1][j ^ a[i]] + R[x - 1][j ^ b[i]];
      if (R[x][j] >= MOD) R[x][j] -= MOD;
    }
  }
  for (int j = 0; j < 64; ++ j) {
    for (int i = 0; i < s; ++ i) {
      u[i].x = u[i].y = 0;
      v[i].x = v[i].y = 0;
    }
    for (int i = 1; i <= n1; ++ i) u[i].x = L[i][j];
    for (int i = 1; i <= n2; ++ i) v[i].x = R[i][j];
    fft(u, s, false); fft(v, s, false);
    for (int i = 0; i < s; ++ i) u[i] = u[i] * v[i];
    fft(u, s, true);
    for (int i = 0; i <= n1 + n2; ++ i) {
      ret[i] += (LL)(u[i].x + 0.5) % MOD;
    }
  }
  for (int i = 1; i <= r - l; ++ i) ret[i] %= MOD;
}

int main() {
  for (int i = 0; i < W; ++ i) {
    flt x = i * 2 * PI / W;
    pw[i] = Complex(cos(x), sin(x));
    ipw[i] = Complex(cos(-x), sin(-x));
  }
  scanf("%d%d", &n, &MOD);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  for (int i = 0; i < n; ++ i) scanf("%d", b + i);
  for (int i = 1; i <= n; ++ i) ret[i] = 0;
  solve(0, n);
  for (int i = 1; i <= n; ++ i) {
    printf("%d\n", ret[i]);
  }
  return 0;
}

