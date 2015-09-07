#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char s[20][20];
bool nonzero[256];
int mp[256], n, m;
int l[20];
LL pw[20];

int dfs(int d, int p, int msk, LL sum) {
  if (sum < 0) return 0;
  if (d == n) return sum == 0;
  if (p == l[d]) return dfs(d + 1, 0, msk, sum);
  int ret(0);
  if (d == 0) {
    int c = s[d][p];
    if (mp[c] == -1) {
      for (int i = 0; i < 10; ++ i) if (msk >> i & 1) {
        if (!i && nonzero[c]) continue;
        mp[c] = i;
        ret += dfs(d, p + 1, msk ^ (1 << i), sum + i * pw[p]);
        mp[c] = -1;
      }
    }
    else ret += dfs(d, p + 1, msk, sum + mp[c] * pw[p]); 
  }
  else {
    int c = s[d][p];
    if (mp[c] == -1) {
      for (int i = 0; i < 10; ++ i) if (msk >> i & 1) {
        if (!i && nonzero[c]) continue;
        mp[c] = i;
        ret += dfs(d, p + 1, msk ^ (1 << i), sum - i * pw[p]);
        mp[c] = -1;
      }
    }
    else ret += dfs(d, p + 1, msk, sum - mp[c] * pw[p]); 
  }
  return ret;
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < 20; ++ i) pw[i] = pw[i - 1] * 10;
  while (scanf("%d", &n) == 1) {
    memset(nonzero, 0, sizeof(nonzero));
    for (int i = 0; i < n; ++ i) {
      int x = n - i - 1;
      scanf("%s", s[x]);
      nonzero[s[x][0]] = 1;
      l[x] = strlen(s[x]);
      reverse(s[x], s[x] + l[x]);
    }
    memset(mp, -1, sizeof(mp));
    printf("%d\n", dfs(0, 0, 1023, 0));
  }
  return 0;
}