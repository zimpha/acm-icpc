#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    LL H, L; scanf("%lld%lld", &H, &L);
    printf("Case %d: ", cas);
    if (L == 1) {
      printf("%lld\n", H + 1);
      continue;
    }
    LL s(1), h(0), tot(0);
    for (; ; ) {
      if (s * 2 > L) break;
      s *= 2; ++ h;
    }
    tot = L * 2 - 1;
    if (s != L) {
      tot += 2 * (L - s) * (H - h - 1);
      tot += (s * 2 - L) * (H - h);
    }
    else {
      tot += L * (H - h);
    }
    printf("%lld\n", tot);
  }
  return 0;
}
