#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char *p;
int get() {
  int r(0);
  while (isdigit(*p)) {
    r = r * 10 + *p - '0';
    p ++;
  }
  return r;
}

int main() {
  char s[100];
  int ret(0);
  while (scanf("%s", s) == 1) {
    if (s[0] == '#' || s[0] == '$') {
      printf("%d:%02d\n", ret / 60, ret % 60);
      ret = 0;
      if (s[0] == '#') break;
    }
    else if (s[0] == '+') {
      p = s + 1;
      ret += get() * 60; ++ p;
      ret += get();
    }
    else {
      p = s + 1;
      ret -= get() * 60; ++ p;
      ret -= get();
    }
  }
  return 0;
}

