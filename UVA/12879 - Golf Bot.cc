#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double flt;
typedef pair<int, int> PII;

namespace FFT {
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
  static const int W = 1 << 20;
  static const flt PI = acos(-1.0);
  static Complex pw[W], ipw[W];
  static void init() {
    for (int i = 0; i < W; ++ i) {
      flt x = i * 2 * PI / W;
      pw[i] = Complex(cos(x), sin(x));
      ipw[i] = Complex(cos(-x), sin(-x));
    }
  }
  static void fft(Complex *f, int n, bool inv) {
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
}
const int MAXN = 200000 + 10;

FFT::Complex u[FFT::W];

int main() {
  int n, m;
  FFT::init();
  while (scanf("%d", &n) == 1) {
    int s = 1 << 19;
    for (int i = 0; i < s; ++ i) {
      u[i].x = u[i].y = 0;
    }
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      u[x].x = 1;
    }
    u[0].x = 1;
    FFT::fft(u, s, 0);
    for (int i = 0; i < s; ++ i) u[i] = u[i] * u[i];
    FFT::fft(u, s, 1);
    scanf("%d", &m); n = 0;
    for (int i = 0; i < m; ++ i) {
      int x; scanf("%d", &x);
      if ((int)(u[x].x + 0.5)) ++ n;
    }
    printf("%d\n", n);
  }
  return 0;
}

