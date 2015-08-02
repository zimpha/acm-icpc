#include <bits/stdc++.h>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    if (n % 2 == 1 && m % 2 == 1) puts("Vanka");
    else puts("Tuzik");
  }
  return 0;
}