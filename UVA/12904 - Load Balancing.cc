#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int cnt[200]; memset(cnt, 0, sizeof(cnt));
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      cnt[x] ++;
    }
    for (int i = 1; i <= 160; ++ i) cnt[i] += cnt[i - 1];
    double ret(1e9);
    int ra, rb, rc;
    for (int a = 0; a <= 160; ++ a) {
      for (int b = a + 1; b <= 160; ++ b) {
        for (int c = b + 1; c < 160; ++ c) {
          double avg = n / 4.0;
          double diff = abs(cnt[a] - avg) + abs(cnt[b] - cnt[a] - avg);
          diff += abs(cnt[c] - cnt[b] - avg) + abs(cnt[160] - cnt[c] - avg);
          if (diff < ret) ret = diff, ra = a, rb = b, rc = c;
        }
      }
    }
    printf("Case %d: %d %d %d\n", cas, ra, rb, rc);
  }
  return 0;
}

