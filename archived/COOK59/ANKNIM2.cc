#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1 << 20;

namespace FFT {
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
  static const int W = 1 << 18;
  static const flt PI = acos(-1.0);
  static Complex pw[W], ipw[W];
  static void init() {
    for (int i = 0; i < W; ++ i) {
      flt x = i * 2 * PI / W;
      pw[i] = Complex(cos(x), sin(x));
      ipw[i] = Complex(cos(-x), sin(-x));
    }
  }
  static void trans(Complex *f, int n, bool inv) {
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

int ret[MAXN];
PII a[MAXN];

void solve1(int l, int r) {
  for (int i = l; i < r; ++ i) {
    for (int j = l; j < i; ++ j) {
      ret[a[i].second - a[j].second] ++;
    }
  }
}

FFT::Complex u[FFT::W], v[FFT::W];

void solve2(int l, int r, int n) {
  int mu = a[r - 1].second, mv = n - a[l].second;
  int s(1); while (s <= mu + mv) s <<= 1;
  for (int i = 0; i < s; ++ i) {
    u[i].x = v[i].x = 0;
    u[i].y = v[i].y = 0;
  }
  for (int i = l; i < r; ++ i) {
    u[a[i].second].x = v[n - a[i].second].x = 1;
  }
  FFT::trans(u, s, 0); FFT::trans(v, s, 0);
  for (int i = 0; i < s; ++ i) u[i] = u[i] * v[i];
  FFT::trans(u, s, 1);
  for (int i = n + 1; i < s; ++ i) ret[i - n] += (int)(u[i].x + 0.5);
}

int main() {
  FFT::init();
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 0; i <= n; ++ i) ret[i] = 0;
    int s(0); a[0] = PII(0, 0);
    for (int i = 1; i <= n; ++ i) {
      int x; scanf("%d", &x);
      a[i] = PII(s ^= x, i);
    }
    sort(a, a + n + 1);
    int lim = 5000;
    for (int i = 0, j; i <= n; i = j) {
      for (j = i; j <= n && a[i].first == a[j].first; ++ j);
      if (j - i <= lim) solve1(i, j);
      else solve2(i, j, n);
    }
    for (int i = 1; i <= n; ++ i) {
      printf("%d%c", ret[i], " \n"[i == n]);
    }
  }
  return 0;
}