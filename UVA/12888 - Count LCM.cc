#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 1000000 + 10;

int mu[MAXN];

int main() {
  for (int i = 1; i < MAXN; ++ i) {
    mu[i] += i == 1;
    for (int j = i + i; j < MAXN; j += i) {
      mu[j] -= mu[i];
    }
    mu[i] += mu[i - 1];
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    LL ret(0);
    for (int i(1), j; i <= min(n, m); i = j + 1) {
      j = min(n / (n / i), m / (m / i));
      ret += (LL)(mu[j] - mu[i - 1]) * (n / i) * (m / i);
    }
    printf("%lld\n", ret);
  }
  return 0;
}

