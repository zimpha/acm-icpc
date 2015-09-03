#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    char s[100], t[100]; scanf("%s%s", s, t);
    bool flag = 1;
    for (int i = 0; s[i]; ++ i) {
      if (s[i] == '?' || t[i] == '?') continue;
      flag &= s[i] == t[i];
    }
    if (flag) puts("Yes");
    else puts("No");
  }
  return 0;
}

