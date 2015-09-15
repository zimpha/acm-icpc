#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long LL;
const int MAXN = 100000 + 10;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y):x(x), y(y) {}
  Point operator+(const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator-(const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  LL det(const Point &rhs) const {
    return 1ll * x * rhs.y - 1ll * y * rhs.x;
  }
};

struct Convex {
  vector<Point> P;
  void clear() {P.clear();}
  void add(const Point &o) {
    while (P.size() > 1 && (o - P[P.size() - 2]).det(P.back() - P[P.size() - 2]) <= 0) P.pop_back();
    P.push_back(o);
  }
  bool ask(const Point &a, const Point &b) {
    int l = 0, r = P.size() - 2;
    while (l < r) {
      int m = (l + r) >> 1;
      if ((P[m] - a).det(b - a) < (P[m + 1] - a).det(b - a)) r = m;
      else l = m + 1;
    }
    return (P[l] - a).det(b - a) < 0 || (P[l + 1] - a).det(b - a) < 0;
  }
};

Point P[MAXN];
Convex T[MAXN << 2];

void build(int rt, int l, int r) {
  if (l >= r) return; T[rt].clear();
  for (int i = l; i <= r; ++ i) T[rt].add(P[i]);
  if (r - l <= 1) return;
  build(lson, l, mid); build(rson, mid, r);
}

int ask(int rt, int l, int r, int L, int R, const Point &a, const Point &b) {
  if (R <= l || L >= r) return 0;
  if (L <= l && R >= r) {
    if (!T[rt].ask(a, b)) return 0;
    if (r - l == 1) return l + 1;
  }
  int ret = ask(lson, l, mid, L, R, a, b);
  if (ret != 0) return ret;
  else return ask(rson, mid, r, L, R, a, b);
}

int main() {
  int T; scanf("%d",  &T);
  while (T --) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d%d", &P[i].x, &P[i].y);
    build(1, 0, n - 1);
    for (int i = 0; i < n - 2; ++ i) {
      printf("%d ", ask(1, 0, n - 1, i + 1, n - 1, P[i], P[i + 1]));
    }
    puts("0");
  }
  return 0;
}
