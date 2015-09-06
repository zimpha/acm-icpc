#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  int det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
};

struct Line {
  Point a, b;
  Line() {}
  Line(const Point &a, const Point &b): a(a), b(b) {}
  int side(const Point &p) const {
    return (b - a).det(p - a);
  }
};

bool inside(const Line &a, const Line &b, const Line &c, const Point &p) {
  return a.side(p) <= 0 && b.side(p) >= 0 && c.side(p) >= 0;
}

bool ccw(const Point &a, const Point &b, const Point &c) {
  return (b - a).det(c - a) > 0;
}

int main() {
  Point a, b, c, d, e;
  while (scanf("%d%d%d%d%d%d%d%d%d%d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y, &e.x, &e.y) == 10) {
    int n; scanf("%d", &n);
    if (!ccw(a, e, d) || !ccw(e, d, c) || !ccw(d, c, b) || !ccw(c, b, a) || !ccw(b, a, e)) {
      puts("Impossible");
      for (int i = 0; i < n; ++ i) scanf("%*d%*d");
    }
    else {
      for (int i = 0; i < n; ++ i) {
        Point p; scanf("%d%d", &p.x, &p.y);
        if (inside(Line(a, c), Line(a, d), Line(e, b), p) ||
            inside(Line(e, b), Line(e, c), Line(d, a), p) ||
            inside(Line(d, a), Line(d, b), Line(c, e), p) ||
            inside(Line(c, e), Line(c, a), Line(b, d), p) ||
            inside(Line(b, d), Line(b, e), Line(a, c), p)) puts("Yes");
        else puts("No");
      }
    }
  }
  return 0;
}

