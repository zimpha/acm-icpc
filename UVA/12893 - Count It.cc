#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    LL n; scanf("%lld", &n);
    printf("%d\n", __builtin_popcountll(n));
  }
  return 0;
}

