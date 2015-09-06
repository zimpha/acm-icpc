#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
char s[MAXN];
int nx[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%s", s);
    int n = strlen(s); nx[0] = -1;
    for (int i = 1, j = -1; i < n; ++ i) {
      while (j >= 0 && s[j + 1] != s[i]) j = nx[j];
      nx[i] = s[j + 1] == s[i] ? ++ j : j;
    }
    int T = n - 1 - nx[n - 1];
    if (nx[n - 1] == -1 || n % T) printf("%d\n", n);
    else printf("%d\n", T);
  }
  return 0;
}
