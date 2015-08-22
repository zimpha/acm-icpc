#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
int x[MAXN], y[MAXN], n; 

int main() {
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; ++ i) {
      scanf("%d%d", x + i, y + i);
      x[i] *= 2; y[i] *= 2;
    }
    int ret(1);
    for (int i = 0; i + 1 < n; ++ i) {
      int sx = x[i + 1], sy = y[i + 1];
      int vx = y[i] - y[i + 1], vy = x[i + 1] - x[i];
      bool flag = 1;
      for (int j = i + 1; j < n && flag; ++ j) {
        int dx = x[j] - sx, dy = y[j] - sy;
        LL sgn = (LL)vx * dy - (LL)vy * dx;
        if (sgn > 0) {flag = 0; break;}
      }
      if (!flag) {ret = 0; break;}
    }
    if (ret) puts("Fair");
    else puts("Unfair");
  }
  return 0;
}