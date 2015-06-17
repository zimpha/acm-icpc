#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
  bool operator < (const Point &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
};

vector<Point> poly[MAXN];
map<Point, int> mp;
int lev[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int N; scanf("%d", &N);
    mp.clear();
    for (int i = 0; i < N; ++ i) {
      int m; scanf("%d", &m);
      poly[i].clear();
      for (int j = 0; j < m; ++ j) {
        int x, y; scanf("%d%d", &x, &y);
        poly[i].push_back(Point(x, y));
        mp[Point(x, y)] = i;
      }
    }
    for (int i = 0; i < N; ++ i) {
      int id = mp.begin()->second;
      lev[id] = i;
      for (auto &x: poly[id]) mp.erase(x);
    }
    for (int i = 0; i < N; ++ i) printf("%d ", N - 1 - lev[i]);
    puts("");
  }
  return 0;
}

