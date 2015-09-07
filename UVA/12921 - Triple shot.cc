#include <bits/stdc++.h>
using namespace std;

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
} a, b, c;

int main() {
  while (scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y) == 6) {
    flt x = (c - b).dot(a - c), y = (c - b).det(a - b);
    if (y == 0) puts("Impossible");
    else {
      Point m = (a + b) / 2 + (a - b).rot() * x / y / 2;
      printf("%.10f %.10f\n", m.x, m.y);
    }
  }
  return 0;
}
