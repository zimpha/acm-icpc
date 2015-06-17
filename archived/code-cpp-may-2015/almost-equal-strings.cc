#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int MAXN = 1000000 + 10, seed = 1e9 + 7;
char s[MAXN];
LL h[MAXN], pw[MAXN];
int n;

LL get(int i, int l) {
  return h[i] - h[i + l] * pw[l];
}

int lcp(int a, int b) {
  int left = 0, right = min(n - a, n - b);
  while (left < right) {
    int mid = (left + right + 1) >> 1;
    if (get(a, mid) == get(b, mid)) left = mid;
    else right = mid - 1;
  }
  return left;
}

bool check(int a, int b, int c, int d) {
  if (b - a != d - c) return false;
  int l = lcp(a, c);
  if (l >= b - a + 1) return true;
  a += l + 1; c += l + 1;
  l = lcp(a, c);
  return l >= b - a + 1;
}

int main() {
  scanf("%d%s", &n, s); pw[0] = 1; h[n] = 0;
  for (int i = 1; i <= n; ++ i) {
    pw[i] = pw[i - 1] * seed;
  }
  for (int i = n - 1; i >= 0; -- i) {
    h[i] = h[i + 1] * seed + s[i];
  }
  int q; scanf("%d", &q);
  while (q --) {
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    -- a; -- b; -- c; -- d;
    if (check(a, b, c, d)) puts("SIMILAR");
    else puts("DIFFERENT");
  }
  return 0;
}
