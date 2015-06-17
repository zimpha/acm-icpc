#include <bits/stdc++.h>
using namespace std;

char s[10000];

int main() {
  int q; scanf("%s%d", s, &q);
  for (int i = 0; i < q; ++ i) {
    int a, b; scanf("%d%d", &a, &b);
    reverse(s + a, s + b + 1);
    puts(s);
  }
  return 0;
}
