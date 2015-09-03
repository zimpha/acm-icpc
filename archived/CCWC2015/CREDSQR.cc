#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
vector<PII> fac[200];

int main() {
  for (int i = 1; i <= 100; ++ i) {
    int n = i;
    for (int x = 2; x * x <= n; ++ x) {
      if (n % x == 0) {
        int c(0);
        while (n % x == 0) n /= x, ++ c;
        if (c & 1) ++ c;
        fac[i].push_back(PII(x, c));
      }
    }
    if (n > 1) fac[i].push_back(PII(n, 2));
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) {
      int a; scanf("%d", &a);
      for (auto &x: fac[a]) {
        mp[x.first] = max(mp[x.first], x.second);
      }
    }
    int ret(1);
    for (auto &x: mp) {
      for (int i = 0; i < x.second; ++ i) {
        ret = 1ll * ret * x.first % MOD;
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}

