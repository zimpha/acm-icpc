#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

char s[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%s", s);
    int n = strlen(s), cnt(-1);
    for (int i = 0; i < n; ++ i) {
      if (s[i] == 'a') ++ cnt;
      else -- cnt;
    }
    int ret = abs(cnt), sum(-1);
    int m1(0), m2(0);
    if (cnt < 0) sum -= cnt;
    for (int i = 0; i < n; ++ i) {
      if (s[i] == 'a') ++ sum;
      else {
        sum --;
        if (-sum > m1) m2 = m1, m1 = -sum;
        else if (-sum > m2) m2 = -sum;
      }
    }
    printf("Case %d: %d\n", cas, ret + m1 + m2);
  }
  return 0;
}
