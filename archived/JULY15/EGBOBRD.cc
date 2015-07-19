#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N; LL K; scanf("%d%lld", &N, &K);
    multiset<LL> S;
    LL ret(0);
    for (int i = 0; i < N; ++ i) {
      int x; scanf("%d", &x);
      while (!S.empty() && x) {
        int v = *S.begin() - i;
        S.erase(*S.begin());
        if (v > x) {
          S.insert(v - x + i);
          x = 0;
        }
        else x -= v;
      }
      if (x % K == 0) ret += x / K;
      else ret += x / K + 1;
      x %= K;
      if (x) S.insert(K - x + i);
    }
    printf("%lld\n", ret);
  }
  return 0;
}