#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const int MAXN = 20, MAXM = 10000 + 10;
flt p[MAXN][MAXM];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < m; ++ j) {
        scanf("%lf", &p[i][j]);
      }
    }
    if (n <= 4 && m <= 4) {
      flt sum(0);
      for (int i = 0; i < n; ++ i) {
        for (int j = 1; j < m; ++ j) {
          p[i][0] *= p[i][j];
        }
        sum += p[i][0];
      }
      if (sum == 0) puts("0");
      else printf("%.19f\n", p[0][0] / sum);
      continue;
    }
    flt ret(1);
    for (int i = 1; i < n; ++ i) {
      flt tmp(1);
      for (int j = 0; j < m; ++ j) {
        tmp *= p[i][j] / p[0][j];
      }
      ret += tmp;
    }
    printf("%.19f\n", 1.0 / ret);
  }
  return 0;
}

