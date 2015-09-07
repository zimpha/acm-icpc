#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    char s[100]; scanf("%s", s);
    LL n; sscanf(s, "%lld", &n);
    int l = strlen(s);
    for (int i = 0; s[i]; ++ i) {
      LL r(1), p(s[i] - '0');
      for (int j = 0; j < l; ++ j) r *= p;
      n -= r;
    }
    if (n == 0) puts("Armstrong");
    else puts("Not Armstrong");
  }
  return 0;
}

