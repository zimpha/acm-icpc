#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 10000 + 10;
int x[MAXN], y[MAXN], n;

int main() {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; ++ i) {
    scanf("%d%d", x + i, y + i);
  }
  x[0] = 0; y[0] = 1;
  bool flag = 1;
  for (int i = 1; i <= n; ++ i) {
    int dx = abs(x[i] - x[i - 1]);
    int dy = abs(y[i] - y[i - 1]);
    if (dx < dy) flag = 0;
  }
  if (flag) puts("YES");
  else puts("NO");
  return 0;
}
