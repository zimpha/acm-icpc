#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;
const int SX = 1e9 + 7, SY = 65537;

LL H[MAXN][MAXN], xw[MAXN], yw[MAXN];
char s[MAXN][MAXN], t[MAXN][MAXN];
int n, m, p, q;

int main() {
  xw[0] = yw[0] = 1;
  for (int i = 1; i < MAXN; ++ i) {
    xw[i] = xw[i - 1] * SX;
    yw[i] = yw[i - 1] * SY;
  }
  while (scanf("%d%d%d%d", &p, &q, &n, &m) == 4) {
    for (int i = 1; i <= p; ++ i) scanf("%s", t[i] + 1);
    for (int i = 1; i <= n; ++ i) scanf("%s", s[i] + 1);
    for (int i = 1; i <= p; ++ i) {
      for (int j = 1; j <= q; ++ j) {
        H[i][j] = H[i - 1][j] * SX + H[i][j - 1] * SY + t[i][j];
        H[i][j] -= H[i - 1][j - 1] * SX * SY;
      }
    }
    int ret(0);
    LL target = H[p][q];
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        H[i][j] = H[i - 1][j] * SX + H[i][j - 1] * SY + s[i][j];
        H[i][j] -= H[i - 1][j - 1] * SX * SY;
        if (i >= p && j >= q) {
          LL tmp = H[i][j] - H[i - p][j] * xw[p] - H[i][j - q] * yw[q];
          tmp += H[i - p][j - q] * xw[p] * yw[q];
          ret += tmp == target;
        }
      }
    }
    printf("%d\n", ret);
  }
  return 0;
}

