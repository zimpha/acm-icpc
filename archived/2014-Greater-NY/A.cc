#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K, a[30]; scanf("%d", &K);
    for (int i = 0; i < 20; ++ i) scanf("%d", a + i);
    int ret(0);
    for (int i = 0; i < 20; ++ i) {
      int mx = i;
      for (int j = i; j < 20; ++ j) {
        if (a[j] < a[mx]) mx = j;
      }
      ret += mx - i;
      for (int j = mx; j >= i; -- j) a[j] = a[j - 1];
    }
    printf("%d %d\n", K, ret);
  }
  return 0;
}

