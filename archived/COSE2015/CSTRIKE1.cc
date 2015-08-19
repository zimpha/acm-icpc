#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

bool dp[300000];
int a[1000];
int n, s;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n); s = 0;
    for (int i = 0; i < n; ++ i) {
      scanf("%d", a + i);
      s += a[i];
    }
    if (s & 1) {puts("NO"); continue;}
    memset(dp, 0, sizeof(dp[0]) * (s + 1));
    dp[0] = 1;
    for (int i = 0; i < n; ++ i) {
      for (int j = s; j >= a[i]; -- j) {
        dp[j] |= dp[j - a[i]];
      }
    }
    if (dp[s / 2]) puts("YES");
    else puts("NO");
  }
  return 0;
}

