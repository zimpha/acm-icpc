#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100;
LL C[MAXN][MAXN];

int main() {
  for (int i = 0; i < MAXN; ++ i) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; ++ j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  int n; scanf("%d", &n);
  int m[100], s(0);
  for (int i = 0; i < n; ++ i) {
    scanf("%d", m + i);
    s += m[i];
  }
  LL ret(1);
  for (int i = 0; i < n; ++ i) {
    ret *= C[s][m[i]];
    s -= m[i];
  }
  printf("%lld\n", ret);
  return 0;
}

