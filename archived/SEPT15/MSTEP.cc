#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500 * 500 + 10;

PII p[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        int x; scanf("%d", &x);
        p[x] = PII(i, j);
      }
    }
    int ret(0);
    for (int i = 2; i <= n * n; ++ i) {
      ret += abs(p[i].first - p[i - 1].first) + abs(p[i].second - p[i - 1].second);
    }
    printf("%d\n", ret);
  }
  return 0;
}
