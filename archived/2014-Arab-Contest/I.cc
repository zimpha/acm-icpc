#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

set<string> S;

int dfs(int n, int d, char s[]) {
  if (n < 0) {
    S.insert(s);
    return 1;
  }
  int c(0);
  if (s[n] + d <= '9') {
    s[n] += d;
    c += dfs(n - 1, d, s);
    s[n] -= d;
  }
  if (s[n] - d >= '0') {
    s[n] -= d;
    c += dfs(n - 1, d, s);
    s[n] += d;
  }
  return c;
}

void expand(char s[]) {
  int n = strlen(s);
  S.insert(s);
  for (int d = 1; d <= 9; ++ d) {
    int cnt = dfs(n - 1, d, s);
    if (cnt == 0) break;
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n; scanf("%d", &n);
    int ret(0), cnt(0);
    S.clear();
    for (int i = 0; i < n; ++ i) {
      char s[100]; scanf("%s", s);
      if (!S.count(s)) {
        expand(s);
        ++ cnt;
      }
      ret = max(ret, cnt);
    }
    printf("Case %d: %d\n", cas, ret);
  }
  return 0;
}