#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  int T; cin >> T;
  for (int _ = 0; _ < T; ++ _) {
    int sx, sy, ex, ey, bx, by, n;
    cin >> n >> sx >> sy >> ex >> ey >> bx >> by;
    int d = abs(sx - ex) + abs(sy - ey);
    if (sx == ex && sx == bx) {
      if (min(sy, ey) <= by && by <= max(sy, ey)) d += 2;
    }
    if (sy == ey && sy == by) {
      if (min(sx, ex) <= bx && bx <= max(sx, ex)) d += 2;
    }
    cout << d << endl;
  }
  return 0;
}

