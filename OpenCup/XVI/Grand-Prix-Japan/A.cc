#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 10000 + 10, MAXM = 100 + 10;

char s[MAXM][MAXN];
int n, m;

int main() {
  scanf("%d%d", &n, &m);
  int W(0), E(0);
  for (int i = 0; i < m; ++ i) {
    scanf("%s", s[i]);
    for (int j = 0; j < n; ++ j) {
      W += s[i][j] == 'W';
    }
  }
  int ret(W + E), x(0);
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < m; ++ j) {
      if (s[j][i] == 'W') W --;
      else E ++;
    }
    if (W + E < ret) ret = W + E, x = i + 1;
  }
  printf("%d %d\n", x, x + 1);
  return 0;
}

