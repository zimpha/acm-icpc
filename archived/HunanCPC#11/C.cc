#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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

struct Line {
  Point a, b; // a->b
  flt ang;
  Line() {}
  Line(const Point &a, const Point &b): a(a), b(b) {
    ang = atan2(b.y - a.y, b.x - a.x);
  }
  bool operator < (const Line &l) const {
    int res = sgn(ang - l.ang);
    return res == 0 ? l.side(a) >= 0: res < 0;
  }
  int side(const Point &p) const {// 1: left, 0: on, -1:right
    return sgn((b - a).det(p - a));
  }
  Point inter(const Line &l) const {
    flt k = (l.a - l.b).det(a - l.b);
    k = k / (k - (l.a - l.b).det(b - l.b));
    return a + (b - a) * k;
  }
};

bool onSeg(const Point &A, const Point &B, const Point &O) {
  return sgn((A-O).det(B-O)==0)&&sgn((A-O).dot(B-O))<=0;
}
bool intersect(const Point &A, const Point &B, const Point &C, const Point &D, Point &res) {
  Point AB(B-A), CD(D-C);
  if (sgn(AB.det(CD))==0) return false; // 平行
  int d1=sgn(AB.det(C-A))*sgn(AB.det(D-A));
  int d2=sgn(CD.det(A-C))*sgn(CD.det(B-C));
  res=A+(B-A)*((D-C).det(C-A)/(D-C).det(B-A));
  return d1<0&&d2<0;
}
int inPolygon(vector<Point> &P, Point O) {
  int cnt=0, n = P.size();
  for (int i=0;i<n;++i) {
    if (onSeg(P[i],P[(i+1)%n],O)) return 2;
    int k=sgn((P[(i+1)%n]-P[i]).det(O-P[i]));
    int d1=sgn(P[i].y-O.y),d2=sgn(P[(i+1)%n].y-O.y);
    cnt+=(k>0&&d1<=0&&d2>0)-(k<0&&d2<=0&&d1>0);
  }
  return cnt!=0;
}
bool inPolygon(vector<Point> &P, Point A, Point B) {
  if (inPolygon(P, A) == 0 || inPolygon(P, B) == 0) return 0;
  int n = P.size();
  vector<Point> v;
  for (int i = 0; i < n; ++ i) {
    Point tmp;
    if (intersect(A, B, P[i], P[(i+1)%n], tmp)) return 0;
    if (onSeg(A, B, P[i])) v.push_back(P[i]);
  }
  sort(v.begin(), v.end());
  for (size_t i = 1; i < v.size(); ++ i) {
    Point O = (v[i] + v[i - 1]) / 2;
    if (inPolygon(P, O) == 0) return 0;
  }
  return 1;
}

bool halfplane(vector<Line> v) {
  sort(v.begin(), v.end());
  deque<Line> q; q.push_back(v[0]);
  deque<Point> ans;
  for (size_t i = 1; i < v.size(); ++ i) {
    if (sgn(v[i].ang - v[i - 1].ang) == 0) continue;
    while (ans.size() && v[i].side(ans.back()) < 0) ans.pop_back(), q.pop_back();
    while (ans.size() && v[i].side(ans.front()) < 0) ans.pop_front(), q.pop_front();
    ans.push_back(q.back().inter(v[i])); q.push_back(v[i]);
  }
  while (ans.size() && q.front().side(ans.back()) < 0) ans.pop_back(), q.pop_back();
  while (ans.size() && q.back().side(ans.front()) < 0) ans.pop_front(), q.pop_front();
  if (q.size() <= 2) return false;
  vector<Point> pt(ans.begin(), ans.end());
  pt.push_back(q.front().inter(q.back()));
  sort(pt.begin(), pt.end());
  pt.erase(unique(pt.begin(), pt.end()), pt.end());
  return pt.size() > 2;
}

struct Triangle {
  Point a, b, c;
  Triangle() {}
  Triangle(const Point &_a, const Point &_b, const Point &_c): a(_a), b(_b), c(_c) {
    if (sgn((c - a).det(b - a)) > 0) swap(b, c);
  }
  vector<Line> toHalfplane() const {
    vector<Line> r;
    r.push_back(Line(a, b));
    r.push_back(Line(b, c));
    r.push_back(Line(c, a));
    return r;
  }
};

vector<Point> A, B;
int n, m;

vector<Triangle> getTriangle(vector<Point> pt) {
  vector<Triangle> ret;
  while (pt.size() > 2) {
    int n = pt.size();
    for (int i = 0; i < n; ++ i) {
      Point A = pt[(i-1+n)%n], B = pt[(i+1)%n];
      if (inPolygon(pt, A, B)) {
        ret.push_back(Triangle(A, B, pt[i]));
        /*cerr << "(" << A.x << "," << A.y << ") ";
        cerr << "(" << B.x << "," << B.y << ") ";
        cerr << "(" << pt[i].x << "," << pt[i].y << ") " << endl;*/
        pt.erase(pt.begin() + i);
        break;
      }
    }
  }
  return ret;
}

int main() {
  for (int cas(1); scanf("%d", &n) == 1; ++ cas) {
    A.clear(); B.clear();
    for (int i = 0; i < n; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      A.push_back(Point(x, y));
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      B.push_back(Point(x, y));
    }
    vector<Triangle> TA = getTriangle(A);
    //cerr << endl;
    vector<Triangle> TB = getTriangle(B);
    bool flag = true;
    for (size_t i = 0; i < TA.size() && flag; ++ i) {
      for (size_t j = 0; j < TB.size() && flag; ++ j) {
        vector<Line> la = TA[i].toHalfplane();
        vector<Line> lb = TB[j].toHalfplane();
        for (auto &x: lb) la.push_back(x);
        //cerr << halfplane(la) << endl;
        if (halfplane(la)) flag = false;
      }
    }
    printf("Case %d: %s\n", cas, flag ? "No" : "Yes");
  }
  return 0;
}