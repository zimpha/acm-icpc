#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    LL N; int K;
    scanf("%lld%d", &N, &K);
    LL S = (LL)K * (K + 1);
    if (S < N * 2) puts("-1");
    else if (S == N * 2) puts("0");
    else {
      LL r = (S - N * 2) * 4 + 1;
      double x = pow(r, 0.5);
      x = (x - 1) / 2;
      int ret = floor(x);
      printf("%d\n", ret);
    }
  }
  return 0;
}