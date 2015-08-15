#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;

char s[MAXN];

int main() {
  int A, B;
  while (scanf("%d%d", &A, &B) == 2) {
    scanf("%s", s); B = A - B;
    int n = strlen(s);
    LL ret = 0;
    for (int i = 0, j; i < n; ++ i) if (s[i] == 'W') {
      for (j = n - 1; j > i && s[j] == 'W'; -- j);
      if (i == j) break;
      swap(s[i], s[j]);
      LL cost = (LL)B * (j - i);
      if (cost > A) cost = A;
      ret += cost;
    }
    printf("%lld\n", ret);
  }
  return 0;
}
