#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
double f[20], g[20], a, b;
int n, slices, stacks;

double poly(double r, int n) {
  double u = PI * 2 / n;
  return r * r * sin(u) * n / 2;
}

double fun(double x) {
  double r(0);
  for (int i = 0; i <= n; ++ i) {
    r += f[i] * pow(x, i);
  }
  return r;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++ i) {
      scanf("%lf", f + n - i);
    }
    scanf("%lf%lf", &a, &b);
    scanf("%d%d", &slices, &stacks);
    double s1(0), s2(0);

    for (int i = 0; i <= n * 2; ++ i) g[i] = 0;
    for (int i = 0; i <= n; ++ i) {
      for (int j = 0; j <= n; ++ j) {
        g[i + j] += f[i] * f[j];
      }
    }
    for (int i = 0; i <= n * 2; ++ i) {
      s1 += g[i] / (i + 1) * (pow(b, i + 1) - pow(a, i + 1));
    }
    s1 *= PI;
    double delta = (b - a) / stacks;
    for (int i = 0; i < stacks; ++ i) {
      double x1 = a + i * delta, x2 = x1 + delta;
      double r1 = fun(x1), r2 = fun(x2);
      double a1 = poly(r1, slices), a2 = poly(r2, slices);
      s2 += delta * (a1 + a2 + sqrt(a1 * a2)) / 3;
    }
    double ret = abs(s1 - s2) / s1 * 100;
    printf("Case %d: %.4f\n", cas, ret);
  }
  return 0;
}

