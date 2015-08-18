#include <bits/stdc++.h>
using namespace std;

bool is_pow(int x) {
  return __builtin_popcount(x) == 1;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int A, B; scanf("%d%d", &A, &B);
    int ret(0);
    while (!is_pow(A)) {
      ++ ret;
      if (A & 1) A = (A - 1) / 2;
      else A /= 2;
    }
    if (A > B) ret += __builtin_ctz(A / B);
    else ret += __builtin_ctz(B / A);
    printf("%d\n", ret);
  }
  return 0;
}