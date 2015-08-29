#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int X, N, Y, M; scanf("%d%d%d%d", &X, &N, &Y, &M);
    LL a(0), b(X);
    for (int i = 0; i < N; ++ i) {
      if (a > b) swap(a, b);
      a += b;
    }
    if (a > b) swap(a, b);
    b += Y;
    printf("Case %d: %lld\n", cas, __gcd(a, b));
  }
  return 0;
}

