#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, k; scanf("%d%d", &n, &k);
    int p(0), s(0);
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      p ^= x & 1;
    }
    for (int i = 0; i < k; ++ i) {
      s = p ^ 1; p ^= s;
    }
    if (s) puts("odd");
    else puts("even");
  }
  return 0;
}

