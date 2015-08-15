#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    if (n & 1) puts("0");
    else {
      putchar('9'); n /= 2;
      for (int i = 1; i < n; ++ i) putchar('0'); puts("");
    }
  }
  return 0;
}
