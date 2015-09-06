#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

typedef double flt;
const flt eps = 0, INF = 1e18, PI = acos(-1.0);
flt sqr(flt x) {return x * x;}
int sgn(flt x) {return x<-eps?-1:(x>eps);}
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
} A, B;

Point inter(Point A, Point B, Point C, Point D) {
  return A+(B-A)*((D-C).det(C-A)/(D-C).det(B-A));
}

flt fix(flt x) {
  if (x < 0) x += PI * 2;
  if (x > PI * 2) x -= PI * 2;
  return x;
}

flt L;
Point get(flt x) {
  flt s = (A - B).abs();
  flt y = L - x, k = y / x;
  flt u = s / (1 + k), v = s - u;
  flt l = sqrt(x * y - u * v);
  Point O = A + (B - A) / (k + 1);
  O.y += l; return O;
}

int main() {
  while (scanf("%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &L) == 5) {
    if (sgn(A.x - B.x) > 0) swap(A, B);
    Point O(0, 0);
    if (A.x == B.x) {
      O.x = A.x;
      O.y = min(A.y, B.y) - (L - (A - B).abs()) / 2;
    }
    else if (sgn((A - B).abs() - L) >= 0) {
      if (sgn(A.y - B.y) < 0) O = A;
      else O = B;
    }
    else {
      flt left = 0, right = L;
      for (int _ = 0; _ < 100; ++ _) {
        flt mid = (left + right) / 2;
        O = get(mid);
        if (sgn((O - A).abs() - mid) < 0) right = mid;
        else left = mid;
      }
      O = get(right);
      O.x = A.x + B.x - O.x;
      O.y = A.y + B.y - O.y;
    }
    printf("%.10f %.10f\n", O.x, O.y);
  }
  return 0;
}