#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, d; scanf("%d%d", &n, &d);
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++ i) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    LL ret(0);
    for (int i = 0; i + 1 < n; ) {
      if (v[i] - v[i + 1] < d) ret += v[i] + v[i + 1], i += 2;
      else ++ i;
    }
    printf("%lld\n", ret);
  }
  return 0;
}