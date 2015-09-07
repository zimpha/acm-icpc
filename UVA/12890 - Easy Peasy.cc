#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    map<int, int> mp;
    int n; scanf("%d", &n);
    LL ret(0);
    for (int i = 1, y(-1); i <= n; ++ i) {
      int x; scanf("%d", &x);
      int tmp = mp[x]; mp[x] = i;
      if (tmp > y) y = tmp;
      ret += i - y;
    }
    printf("%lld\n", ret);
  }
  return 0;
}

