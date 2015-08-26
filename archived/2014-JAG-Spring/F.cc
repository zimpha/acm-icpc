#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double flt;
typedef pair<int, int> PII;

const flt eps = 1e-9;

int sgn(flt x) {
  if (x < -eps) return -1;
  else return x > eps;
}

struct Point {
  flt x, y;
  Point() {}
  Point(flt x, flt y): x(x), y(y) {}
  bool operator < (const Point &rhs) const {
    if (sgn(x - rhs.x) != 0) return sgn(x - rhs.x) < 0;
    else return sgn(y - rhs.y) < 0;
  }
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator * (const flt k) const {
    return Point(x * k, y * k);
  }
  Point operator / (const flt k) const {
    return Point(x / k, y / k);
  }
  flt det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
  flt dot(const Point &rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  flt sqr() const {
    return x * x + y * y;
  }
  flt abs() const {
    return hypot(x, y);
  }
};

bool onSeg(Point &A, Point &B, Point &O) {
  return sgn((A - O).det(B - O) == 0) && sgn((A - O).dot(B - O)) <= 0;
}

bool intersect(Point &A, Point &B, Point &C, Point &D, Point &res) {
  if (onSeg(A, B, C)) {res = C; return true;}
  if (onSeg(A, B, D)) {res = D; return true;}
  if (onSeg(C, D, A)) {res = A; return true;}
  if (onSeg(C, D, B)) {res = B; return true;}
  if (sgn((B - A).det(D - C)) == 0) return false; // 平行
  Point AB = B - A, CD = D - C;
  int d1 = sgn(AB.det(C - A)) * sgn(AB.det(D - A));
  int d2 = sgn(CD.det(A - C)) * sgn(CD.det(B - C));
  res = A + (B - A)* ((D - C).det(C - A) / (D - C).det(B - A));
  return d1 <= 0 && d2 <= 0;
}

int inPolygon(Point P[], int n, Point O) {
  int cnt = 0; P[n] = P[0];
  for (int i = 0; i < n; ++ i) {
    if (onSeg(P[i], P[i + 1], O)) return 2;
    int k = sgn((P[i + 1] - P[i]).det(O - P[i]));
    int d1 = sgn(P[i].y - O.y), d2 = sgn(P[i + 1].y - O.y);
    cnt += (k > 0 && d1 <= 0 && d2 > 0);
    cnt -= (k < 0 && d2 <= 0 && d1 > 0);
  }
  return cnt != 0;
}

const int MAXN = 50;
Point P[MAXN];
LL G[MAXN], s[MAXN], U;
int ret, n;

void dfs(int d, int cnt, LL msk) {
  if (msk == U) {ret = cnt; return;}
  if (cnt >= ret || d == n) return;
  if ((msk & G[d]) == G[d]) {
    dfs(d + 1, cnt, msk);
    return;
  }
  if ((msk | s[d]) != U) return;
  dfs(d + 1, cnt, msk);
  dfs(d + 1, cnt + 1, msk | G[d]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    scanf("%lf%lf", &P[i].x, &P[i].y);
    G[i] = 1ll << i;
  }
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) if (i != j) {
      vector<Point> pt;
      Point A = P[i], B = P[j], O; P[n] = P[0];
      for (int k = 0; k < n; ++ k) {
        if (intersect(A, B, P[k], P[k + 1], O)) {
          pt.push_back(O);
        }
      }
      sort(pt.begin(), pt.end());
      bool flag = true;
      for (size_t k = 0; k + 1 < pt.size(); ++ k) {
        O = (pt[k] + pt[k + 1]) * 0.5;
        if (inPolygon(P, n, O) == 0) flag = false;
      }
      if (flag) G[i] |= 1ll << j;
    }
  }
  s[n] = 0; U = (1ll << n) - 1;
  for (int i = n - 1; i >= 0; -- i) s[i] = s[i + 1] | G[i];
  ret = n / 2;
  dfs(0, 0, 0);
  printf("%d\n", ret);
  return 0;
}