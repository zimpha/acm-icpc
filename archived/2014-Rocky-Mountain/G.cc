#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100 + 10;

typedef double flt;
const flt eps = 1e-12, INF = 1e18, PI = acos(-1.0);
flt sqr(flt x) {return x * x;}
int sgn(flt x) {return x<-eps?-1:(x>eps);}
flt fix(flt x) {return sgn(x)==0?0:x;}
struct Point {
  flt x, y;
  Point(flt a=0, flt b=0) : x(a), y(b) {}
  bool operator < (const Point &r) const {
    return sgn(x-r.x)<0||(sgn(x-r.x)==0&&sgn(y-r.y)<0);
  }
  bool operator == (const Point &r) const {
    return sgn(x-r.x)==0&&sgn(y-r.y)==0;
  }
  Point operator *(const flt &k) const {return Point(x*k,y*k);}
  Point operator /(const flt &k) const {return Point(x/k,y/k);}
  Point operator -(const Point &r) const {return Point(x-r.x,y-r.y);}
  Point operator +(const Point &r) const {return Point(x+r.x,y+r.y);}
  flt dot(const Point &r) {return x*r.x+y*r.y;}
  flt det(const Point &r) {return x*r.y-y*r.x;}
  flt sqr() {return x*x+y*y;}
  flt abs() {return hypot(x, y);}
  Point rot() {return Point(-y,x);}
  Point rot(flt A) {return Point(x*cos(A)-y*sin(A),x*sin(A)+y*cos(A));}
  Point trunc(flt a=1.0) {return (*this)*(a/this->abs());}
};

vector<Point> convex_hull(vector<Point> u) {
  sort(u.begin(), u.end()); // 排序+去重, 若题目有保证则可去除
  u.erase(unique(u.begin(), u.end()), u.end());
  if (u.size()<3u) return u;
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
  ret.pop_back();  return ret;
}

int x[MAXN], y[MAXN], N;

int main() {
  while (scanf("%d", &N) == 1) {
    double D, L; scanf("%lf%lf", &D, &L);
    L = L * 1000 / D;
    int mx = 0;
    for (int i = 0; i < N; ++ i) {
      scanf("%d%d", x + i, y + i);
      mx = max(mx, y[i]);
    }
    x[N] = x[0]; y[N] = y[0];
    flt left(0), right(mx);
    for (int _ = 0; _ < 100; ++ _) {
      flt mid = (left + right) * 0.5;
      vector<Point> pt;
      for (int i = 0; i < N; ++ i) {
        if (y[i] <= mid) pt.push_back(Point(x[i], y[i]));
        if (y[i] < mid && y[(i + 1) % N] > mid) {
          double scale = (mid - y[i]) / (y[(i + 1) % N] - y[i]);
          pt.push_back(Point(x[i] + (x[(i + 1) % N] - x[i]) * scale, mid));
        }
        if (y[i] > mid && y[(i + 1) % N] < mid) {
          double scale = (mid - y[i]) / (y[(i + 1) % N] - y[i]);
          pt.push_back(Point(x[i] + (x[(i + 1) % N] - x[i]) * scale, mid));
        }
      }
      pt = convex_hull(pt);
      int n = pt.size(); pt.push_back(pt[0]);
      double area(0);
      for (int i = 0; i < n; ++ i) {
        area += pt[i].det(pt[i + 1]);
      }
      area = abs(area) / 2;
      if (area < L) left = mid;
      else right = mid;
    }
    printf("%.2f\n", left);
  }
  return 0;
}

