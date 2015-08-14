#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, a[12]; scanf("%d", &K);
    for (int i = 0; i < 12; ++ i) scanf("%d", a + i);
    int ret(0);
    while (1) {
      int mx = -1;
      for (int i = 0; i < 12; ++ i) {
        if (a[i] && (mx == -1 || a[i] < a[mx])) mx = i;
      }
      if (mx == -1) break;
      for (int i = mx - 1; a[i]; -- i) a[i] -= a[mx];
      for (int i = mx + 1; a[i]; ++ i) a[i] -= a[mx];
      a[mx] = 0; ++ ret;
    }
    printf("%d %d\n", K, ret);
  }
  return 0;
}

