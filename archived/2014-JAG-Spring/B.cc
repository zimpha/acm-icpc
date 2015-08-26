#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int X, Y, Z, A, B, C, N;

LL CC(int n, int m) {
  if (n < 0) return 0;
  if (m == 0) return 1;
  else if (m == 1) return n;
  else if (m == 2) return (LL)n * (n - 1) / 2;
  return 0;
}

LL calc(int a[], int m, int n) {
  int s = 0;
  for (int i = 0; i < m; ++ i) {
    if (a[i] <= 0) return 0;
    s += a[i];
  }
  if (s < n) return 0; -- n;
  if (m == 0) return n == -1;
  if (m == 1) return 0 <= n && n < a[0];
  if (m == 2) return CC(n, 1) - CC(n - a[0], 1) - CC(n - a[1], 1) + CC(n - s, 1);
  LL ret = CC(n, 2) - CC(n - a[0], 2) - CC(n - a[1], 2) - CC(n - a[2], 2);
  ret += CC(n - a[0] - a[1], 2) + CC(n - a[0] - a[2], 2) + CC(n - a[1] - a[2], 2);
  ret -= CC(n - s, 2);
  return ret;
}

const int MAXN = 1000 + 10;
LL ans[MAXN];

int main() {
  scanf("%d%d%d%d%d%d%d", &X, &Y, &Z, &A, &B, &C, &N);
  int l[3] = {A, B, C}, r[3] = {X - A - 1, Y - B - 1, Z - C - 1};
  int lim = max(l[0], r[0]) + max(l[1], r[1]) + max(l[2], r[2]);
  int a[3], b[3];
  for (int d = 0; d <= lim; ++ d) {
    LL ret = 0;
    for (int mask = 0; mask < 8; ++ mask) {
      for (int i = 0; i < 3; ++ i) {
        if ((mask >> i) & 1) a[i] = l[i];
        else a[i] = r[i];
      }
      ret += calc(a, 3, d);
      int t = 0;
      for (int i = 0; i < 3; ++ i) {
        if ((mask >> i) & 1) b[t ++] = i;
      }
      if (t == 3) continue;
      for (int mm = 0; mm < (1 << t); ++ mm) {
        for (int i = 0; i < t; ++ i) {
          if ((mm >> i) & 1) a[i] = l[b[i]];
          else a[i] = r[b[i]];
        }
        ret += calc(a, t, d);
      }
    }
    ans[d % N] += ret;
  }
  for (int i = 0; i < N; ++ i) {
    if (i) putchar(' ');
    printf("%lld", ans[i]);
  }
  puts("");
  return 0;
}