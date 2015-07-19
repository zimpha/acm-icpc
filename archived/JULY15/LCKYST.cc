#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    LL x; scanf("%lld", &x);
    int c(0), t(0);
    for (int y = x; y % 2 == 0; y /= 2, ++ t);
    for (int y = x; y % 5 == 0; y /= 5, ++ c);
    if (t < c) {
      for (int i = t; i < c; i += 2) {
        x *= 4;
      }
    }
    printf("%lld\n", x);
  }
  return 0;
}

