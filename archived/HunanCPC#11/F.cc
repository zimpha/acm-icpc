#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL gao(int n, int l) {
  LL r(1);
  for (int i = 1; i <= l; ++ i) {
    r = r * (n + i);
    if (r > 1e9) return 2e9;
  }
  return r;
}

int main() {
  for (int cas = 1, n; scanf("%d", &n) == 1; ++ cas) {
    printf("Case %d: ", cas);
    if (n == 1) {puts("Impossible"); continue;}
    int x(n), y(n - 1);
    for (int l = 1; l <= 12; ++ l) {
      int left = 1, right = n;
      while (left < right) {
        int mid = (left + right - 1) / 2;
        if (gao(mid, l) >= n) right = mid;
        else left = mid + 1;
      }
      if (gao(right, l) == n) {
        if (right + l < x) x = right + l, y = right;
      }
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}
