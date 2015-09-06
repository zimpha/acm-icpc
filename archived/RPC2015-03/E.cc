#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 50;
int s[MAXN], n, t;

int main() {
  while (scanf("%d%d", &n, &t) == 2) {
    for (int i = 0; i < n; ++ i) scanf("%d", s + i);
    int x = n / 2, y = n - x, m = 1 << x;
    vector<LL> p(m);
    for (int msk = 0; msk < m; ++ msk) {
      LL r = 0;
      for (int i = 0; i < x; ++ i) {
        if (msk >> i & 1) r += s[i];
      }
      p[msk] = r;
    }
    sort(p.begin(), p.end()); m = 1 << y;
    LL ret(0);
    for (int msk = 0; msk < m; ++ msk) {
      LL r(0);
      for (int i = 0; i < y; ++ i) {
        if (msk >> i & 1) r += s[i + x];
      }
      LL now = t - r;
      ret += upper_bound(p.begin(), p.end(), now) - lower_bound(p.begin(), p.end(), now);
    }
    if (t == 0) -- ret;
    printf("%lld\n", ret);
  }
  return 0;
}
