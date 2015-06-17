#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    static char s[1000];
    scanf("%s", s);
    int n = strlen(s);
    bool flag = s[0] != s[1];
    for (int i = 0; i < n; i += 2) {
      flag &= s[i] == s[0];
    }
    for (int i = 1; i < n; i += 2) {
      flag &= s[i] == s[1];
    }
    puts(flag ? "YES" : "NO");
  }
  return 0;
}
