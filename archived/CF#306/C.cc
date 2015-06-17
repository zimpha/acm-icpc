#include <bits/stdc++.h>
using namespace std;
char s[1000];

bool solve() {
  int n = strlen(s);
  for (int i = 0; i < n; ++ i) {
    if ((s[i] - '0') % 8 == 0) {
      puts("YES");
      printf("%c\n", s[i]);
      return true;
    }
  }
  for (int i = 0; i < n; ++ i) if (s[i] != '0') {
    for (int j = i + 1; j < n; ++ j) {
      if (((s[i] - '0') * 10 + s[j] - '0') % 8 == 0) {
        puts("YES");
        printf("%c%c\n", s[i], s[j]);
        return true;
      }
    }
  }
  for (int i = 0; i < n; ++ i) if (s[i] != '0') {
    for (int j = i + 1; j < n; ++ j) {
      for (int k = j + 1; k < n; ++ k) {
        if (((s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0') % 8 == 0) {
          puts("YES");
          printf("%c%c%c\n", s[i], s[j], s[k]);
          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  scanf("%s", s);
  if (!solve()) puts("NO");
  return 0;
}
