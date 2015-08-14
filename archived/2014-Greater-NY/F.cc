#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K; LL p, q;
    scanf("%d %lld/%lld", &K, &p, &q);
    printf("%d ", K);
    if (q == 1) printf("%lld/%lld\n", 1ll, p + q);
    else if (p < q) printf("%lld/%lld\n", q, q - p);
    else {
      LL dep = p / q;
      LL x = q, y = q * (dep * 2 + 1) - p;
      printf("%lld/%lld\n", x, y);
    }
  }
  return 0;
}

