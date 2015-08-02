#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int cnt[110];
int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int m, x, y; scanf("%d%d%d", &m, &x, &y);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < m; ++ i) {
      int p; scanf("%d", &p);
      int l = max(1, p - x * y), r = min(100, p + x * y);
      cnt[l] ++; cnt[r + 1] --;
    }
    int ret(0);
    for (int i = 1; i <= 100; ++ i) {
      cnt[i] += cnt[i - 1];
      ret += cnt[i] == 0;
    }
    printf("%d\n", ret);
  }
  return 0;
}

