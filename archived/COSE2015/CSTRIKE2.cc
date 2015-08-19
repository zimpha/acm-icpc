#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, mx(0), ret(0); scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", &a[i]);
      mx = max(mx, a[i]);
    }
    vector<int> cnt(mx + 1, 0);
    for (int i = 0; i < n; ++ i) cnt[a[i]] ++;
    for (int g = mx; g >= 1; -- g) {
      int c(0);
      for (int i = g; i <= mx; i += g) c += cnt[i];
      if (c > 1) {ret = g; break;}
    }
    printf("%d\n", ret);
  }
  return 0;
}

