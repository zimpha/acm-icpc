#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;

LL s[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, h; scanf("%d%d", &n, &h);
    int cur = n;
    vector<PII> v;
    for (int i = 0; i < n; ++ i) {
      int l, h; scanf("%d%d", &l, &h);
      v.push_back(PII(l, -1));
      v.push_back(PII(h + 1, 1));
    }
    sort(v.begin(), v.end());
    for (int i = 0, j = 0; i < n; ++ i) {
      for (; j < (int)v.size() && v[j].first == i; ++ j) {
        cur += v[j].second;
      }
      s[i]= cur;
    }
    s[n] = 0;
    LL ret((LL)n * n);
    for (int i = n - 1; i >= 0; -- i) {
      s[i] += s[i + 1];
      if (i + h <= n) ret = min(ret, s[i] - s[i + h]);
    }
    printf("%lld\n", ret);
  }
  return 0;
}