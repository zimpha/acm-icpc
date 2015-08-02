#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
char s[MAXN];

bool is_regular(char *s) {
  int c(0);
  for (int i = 0; s[i]; ++ i) {
    if (s[i] == '(') ++ c;
    else -- c;
    if (c < 0) return 0;
  }
  return c == 0;
}
bool out(int p) {
  for (int i = 0; i < p; ++ i) putchar(s[i]);
  for (int i = p + 1; s[i]; ++ i) putchar(s[i]);
  puts(""); return true;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%s", s);
    int n = strlen(s), k; scanf("%d", &k);
    if (is_regular(s)) {
      bool ok(0);
      for (int i = 1; i < n && !ok; ++ i) {
        if (s[i - 1] == '(' && s[i] == ')') {
          if (-- k == 0) ok = out(i);
        }
      }
      for (int i = n - 2; i >= 0 && !ok; -- i) {
        if (s[i + 1] == ')' && s[i] == '(') {
          if (-- k == 0) ok = out(i);
        }
      }
      if (!ok) puts("-1");
    }
    else {
      if (k != 1) puts("-1");
      else puts(s);
    }
  }
  return 0;
}

