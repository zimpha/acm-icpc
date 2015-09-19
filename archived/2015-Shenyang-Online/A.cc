#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100 + 10, MOD = 10007;
map<int, int> dp[MAXN];
int mark[MAXN];
inline void upd(int &x, int y) {x += y; if (x >= MOD) x -= MOD;}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, p, k; scanf("%d%d%d", &n, &p, &k);
    for (int i = 0; i <= n; ++ i) {
      mark[i] = 1; dp[i].clear();
    }
    for (int i = 0; i < k; ++ i) {
      int x; scanf("%d", &x);
      mark[x] = 0;
    }
    while (!mark[n]) -- n;
    int is(0);
    for (int i = 0; i < p + 2; ++ i) is |= 2 << (i << 1);
    dp[0][is] = 1;
    const int sb[] = {1, p, p + 2}, sf[] = {p * 2 + 2, 4, 0};
    for (int i = 0; i < n; ++ i) {
      for (auto &x: dp[i]) {
        int s = x.first, w = x.second;
        if ((s & 3) == 2 || (!(s & 3) && !mark[i - sb[2] + 1])) upd(dp[i + 1][s >> 2], w);
        if (mark[i + 1]) {
          for (int x = 0; x < 3; ++ x) if (i - sb[x] >= 0 && mark[i - sb[x] + 1]) {
            int a = 1 + (s >> sf[x] & 3); if (a == 3) continue;
            int ns = s & (~(1 << sf[x])); ns &= ~(1 << (sf[x] | 1));
            int ts = ns | (a << sf[x]);
            if ((ts & 3) == 2 || (!(ts & 3) && !mark[i - sb[2] + 1])) {
              upd(dp[i + 1][(ts >> 2) | (1 << sf[0])], w);
            }
            for (int y = x + 1; y < 3; ++ y) if (i - sb[y] >= 0 && mark[i - sb[y] + 1]) {
              int b = 1 + (s >> sf[y] & 3); if (b == 3) continue;
              ts = ns & (~(1 << sf[y])); ts &= ~(1 << (sf[y] | 1));
              ts |= (a << sf[x]) | (b << sf[y]);
              if ((ts & 3) == 2 || (!(ts & 3) && !mark[i - sb[2] + 1])) {
                upd(dp[i + 1][(ts >> 2) | (2 << sf[0])], w);
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < p + 2; ++ i) {
      if (n - (p + 1 - i) >= 1 && !mark[n - (p + 1 - i)]) {
        is ^= 2 << (i << 1);
      }
    }
    printf("Case #%d: %d\n", cas, dp[n][is]);
  }
  return 0;
}