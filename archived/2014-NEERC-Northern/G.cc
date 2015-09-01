#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int w, h;

bool ok(int x1, int y1, int x2, int y2) {
  return x2 - x1 >= w && y2 - y1 >= h;
}

int main() {
  freopen("grave.in", "r", stdin);
  freopen("grave.out", "w", stdout);
  int x1, y1, x2, y2, x3, y3, x4, y4;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
  scanf("%d%d", &w, &h);
  if (ok(x1, y1, x3, y2) | ok(x4, y1, x2, y2) | ok(x1, y4, x2, y2) | ok(x1, y1, x2, y3)) puts("Yes");
  else puts("No");
  return 0;
}

