#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100000 + 10;

struct Point {
  int x, y;
  Point(int a=0, int b=0) : x(a), y(b) {}
  bool operator < (const Point &r) const {
    return x < r.x || (x == r.x && y < r.y);
  }
  Point operator -(const Point &r) const {return Point(x-r.x,y-r.y);}
  Point operator +(const Point &r) const {return Point(x+r.x,y+r.y);}
  LL dot(const Point &r) {return (LL)x*r.x+(LL)y*r.y;}
  LL det(const Point &r) {return (LL)x*r.y-(LL)y*r.x;}
} P[MAXN];

int convex_hull(vector<Point> u) {
  sort(u.begin(), u.end());
  if (u.size()<3u) return u.size();
  vector<Point> ret;
  for (size_t i=0,o=1,m=1;~i;i+=o) {
    while (ret.size()>m) {
      Point A=ret.back()-ret[ret.size()-2],B=ret.back()-u[i];
      if (A.det(B)<0) break; // 改成 <= 0, 保留共线点
      ret.pop_back();
    }
    ret.push_back(u[i]);
    if (i+1==u.size()) m=ret.size(),o=-1;
  }
  ret.pop_back(); return ret.size();
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%d%d", &P[i].x, &P[i].y);
  }
  int h = convex_hull(vector<Point>(P, P + n));
  printf("%d\n", n * 3 - h * 2 - 2);
  return 0;
}