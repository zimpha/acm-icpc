#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
int s[MAXN], d[MAXN], n;

double calc(double t) {
  double r(0), l(1e19);
  for (int i = 0; i < n; ++ i) {
    r = max(r, t * s[i] + d[i]);
    l = min(l, t * s[i] + d[i]);
  }
  return r - l;
}

int main() {
  int k; scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++ i) scanf("%d%d", s + i, d + i);
  double left = 0, right = k;
  for (int _ = 0; _ < 500; ++ _) {
    double m1 = left + (right - left) / 3;
    double m2 = right - (right - left) / 3;
    if (calc(m1) < calc(m2)) right = m2;
    else left = m1;
  }
  printf("%.6f\n", calc(left));
  return 0;
}