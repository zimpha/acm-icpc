#include <bits/stdc++.h>
using namespace std;

int main() {
  static char s[100010];
  scanf("%s", s);
  int n = strlen(s);
  if ((s[n - 1] - '0') & 1) puts("NO");
  else puts("YES");
  return 0;
}