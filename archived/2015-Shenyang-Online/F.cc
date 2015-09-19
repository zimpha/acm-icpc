#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;
char s[MAXN];

int solve() {
  scanf("%s", s);
  int n = strlen(s);
  int ret(0);
  for (int i = 0, j; i < n; ) {
    if (s[i] != 'c' && s[i] != 'f') return -1;
    if (s[i] == 'c') {
      for (j = i + 1; s[j % n] != 'c'; ++ j);
      if (j - i == 1) return -1;
      else if (j - i == 2) return -1;
      ret ++; i = j;
    }
    else ++ i;
  }
  if (ret == 0) ret = (n + 1) / 2;
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int ret = solve();
    printf("Case #%d: %d\n", cas, ret);
  }
  return 0;
}