#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 500 + 10;

int sr[MAXN], sc[MAXN], mp[MAXN][MAXN];
int n, m;

int main() {
  for (int cas(1); scanf("%d%d", &n, &m) == 2; ++ cas) {
    for (int i = 1; i <= n; ++ i) sr[i] = 0;
    for (int i = 1; i <= m; ++ i) sc[i] = 0;
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        scanf("%d", &mp[i][j]);
        sr[i] += mp[i][j];
        sc[j] += mp[i][j];
      }
    }
    int ret(0);
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        ret = max(ret, sr[i] + sc[j] - mp[i][j]);
      }
    }
    int r(1), c(1);
    for (int i = 1; i <= n; ++ i) {
      if (sr[i] > sr[r]) r = i;
    }
    for (int i = 1; i <= m; ++ i) {
      if (sc[i] > sc[c]) c = i;
    }
    printf("Case %d: ", cas);
    if (sc[c] + sr[r] - mp[r][c] == ret) puts("Weak");
    else puts("Strong");
  }
  return 0;
}

