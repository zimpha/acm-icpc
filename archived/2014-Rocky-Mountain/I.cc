#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100;
LL C[MAXN][MAXN];
int a[MAXN], n;

int main() {
  for (int i = 0; i <= 60; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 0; j < i; ++ j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    printf("%lld %lld\n", C[n][m - 1], C[n][m - 1] * (n - m + 1) / n);
  }
  return 0;
}

