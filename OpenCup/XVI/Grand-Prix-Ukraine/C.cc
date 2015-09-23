#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 1000000 + 10;
int vs[MAXN];

int main() {
  fill(vs + 2, vs + MAXN, 1);
  for (int i = 2; i < MAXN; ++ i) if (vs[i]) {
    for (int j = i + i; j < MAXN; j += i) vs[j] = 0;
  }
  int n; scanf("%d", &n);
  int ret(-1), c(0);
  for (int i = 10; i <= 1000000; ++ i) if (vs[i]) {
    int r(0), x(i);
    for (; x; x /= 10) r = r * 10 + x % 10;
    if (vs[r] && r != i) ++ c;
    if (c == n) {ret = i; break;}
  }
  printf("%d\n", ret);
  return 0;
}