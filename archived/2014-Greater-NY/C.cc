#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long wd;
typedef pair<int, int> PII;

wd solve(wd X) {
  wd s = X & 0x80000000, ret(0);
  wd exp = (X & 0x7f000000) >> 24;
  exp -= 64; exp *= 4;
  wd mag = X & 0xffffff;
  if (mag == 0) return 0;
  while ((mag & 0x800000) == 0) {
    mag <<= 1; exp --;
  }
  exp --;
  if ((int)exp > 127) ret = s | 0x7f800000;
  else if ((int)exp < -149) ret = s;
  else if ((int)exp >= -126) {
    mag &= 0x7fffff;
    exp = (exp + 127) << 23, ret = s | exp | mag;
  }
  else {
    while ((int)exp < -126) exp ++, mag >>= 1;
    mag &= 0x7fffff;
    ret = s | mag;
  }
  return ret;
}

int main() {
  int P; scanf("%d", &P);
  for (int _ = 0; _ < P; ++ _) {
    int K; wd X;
    scanf("%d%lX", &K, &X);
    printf("%d %08lX\n", K, solve(X));
  }
  return 0;
}

