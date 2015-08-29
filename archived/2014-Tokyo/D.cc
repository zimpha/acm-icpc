#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const flt inf = 1e9;

int p[20], h[20];
int d, n, b;

flt get(flt s, flt l, int n) {
  flt ret = inf;
  for (int i = 0; i < n; ++ i) {
    if (p[i] >= s && p[i] <= s + l) {
      flt x = p[i] - s;
      ret = min(ret, sqrt((l * x - x * x) / 2.0 / h[i]));
    }
  }
  return ret;
}

int main() {
  while (scanf("%d%d%d", &d, &n, &b) == 3) {
    for (int i = 0; i < n; ++ i) scanf("%d%d", p + i, h + i);
    flt ret(inf);
    for (int i = 1; i <= b + 1; ++ i) {
      flt l = flt(d) / i, vx(inf);
      for (int j = 0; j < i; ++ j) {
        flt s = l * j;
        vx = min(vx, get(s, l, n));
      }
      if (vx == 0) continue;
      flt a = l / 2;
      if (vx >= sqrt(a)) ret = min(ret, sqrt(2.0 * a));
      else ret = min(ret, sqrt(vx * vx + a * a / vx / vx));
    }
    printf("%.10f\n", ret);
  }
  return 0;
}

