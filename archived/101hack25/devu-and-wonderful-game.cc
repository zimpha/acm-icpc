#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    string s; cin >> s;
    while (1) {
      string t; int f(0);
      for (size_t i = 0, j; i < s.size(); i = j) {
        for (j = i; j < s.size() && s[i] == s[j]; ++ j);
        if (j - i == 1) t += s[i];
        else f = 1;
      }
      s = t;
      if (!f) break;
    }
    if (s.size() <= 2) puts("0 0");
    else printf("%d %d\n", 1, int(s.size() + 1) / 4);
  }
  return 0;
}

