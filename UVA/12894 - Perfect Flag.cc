#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int x0, y0, x1, y1, cx, cy, r;
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    scanf("%d%d%d", &cx, &cy, &r);
    int w = y1 - y0, l = x1 - x0;
    int dx = cx - x0, dy = cy - y0;
    //cout << l << " " << w << " " << dx << " " << dy << " " << r << endl;
    if (l == r * 5 && w * 10 == l * 6 && dy * 2 == w && 20 * dx == l * 9) puts("YES");
    else puts("NO");
  }
  return 0;
}

