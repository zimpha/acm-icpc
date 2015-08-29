#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;
const flt eps = 1e-9, inf = 1e9;
const int MAXN = 1000 + 10;

int sgn(flt x) {return x < -eps ? -1 : x > eps;}

struct Point {
  flt x, y;
  Point(): x(0), y(0) {}
  Point(flt x, flt y): x(x), y(y) {}
  bool operator < (const Point &rhs) const {
    return sgn(x - rhs.x) < 0 || (sgn(x - rhs.x) == 0 && sgn(y - rhs.y) < 0);
  }
  bool operator == (const Point &rhs) const {
    return sgn(x - rhs.x) == 0 && sgn(y - rhs.y) == 0;
  }
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator * (const flt &k) const {
    return Point(x * k, y * k);
  }
  Point operator / (const flt &k) const {
    return Point(x / k, y / k);
  }
  flt det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
  flt dot(const Point &rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  flt abs() const {return hypot(x, y);}
  flt ang() const {return atan2(y, x);}
  Point trunc(const flt k) const {
    return *this / abs() * k;
  }
  Point rot() const {
    return Point(y, -x);
  }
} O, T, P[10];

typedef pair<int, double> PID;
const flt r = 100.0, PI = acos(-1.0);
vector<Point> pt;
vector<PID> G[MAXN];
int n;

flt disToSeg(const Point &A, const Point &B, const Point &O) {
  return abs((B - A).det(O - A) / (A - B).abs());
}

bool onSeg(const Point &A, const Point &B, const Point &O) {
  return sgn((A-O).det(B-O)==0)&&sgn((A-O).dot(B-O))<=0;
}

void getCirCir(const Point &A, const Point &B) {
  flt d = (A - B).abs();
  Point u = (A - B).trunc(r);
  Point v = u.rot();
  pt.push_back(A + v); pt.push_back(A - v);
  pt.push_back(B + v); pt.push_back(B - v);
  if (sgn(d - r * 2) > 0) { // more 4 pts
    flt a = acos(r * 2 / d);
    flt base = (B - A).ang();
    pt.push_back(A + Point(cos(base + a), sin(base + a)) * r);
    pt.push_back(A + Point(cos(base - a), sin(base - a)) * r);
    base = (A - B).ang();
    pt.push_back(B + Point(cos(base + a), sin(base + a)) * r);
    pt.push_back(B + Point(cos(base - a), sin(base - a)) * r);
  }
}

void getPtsCir(const Point &A, const Point &O) {
  flt base = (A - O).ang();
  flt a = acos(r / (A - O).abs());
  pt.push_back(O + Point(cos(base + a), sin(base + a)) * r);
  pt.push_back(O + Point(cos(base - a), sin(base - a)) * r);
}

bool ok1(const Point &A, const Point &B) {
  for (int i = 0; i < n; ++ i) {
    flt d = disToSeg(A, B, P[i]);
    if (sgn(d - r) < 0 && sgn((P[i] - A).dot(B - A)) > 0 && sgn((P[i] - B).dot(A - B)) > 0) return false;
  }
  return true;
}

flt fix(flt x) {
  if (sgn(x) < 0) x += PI * 2;
  if (sgn(x - PI * 2) >= 0) x -= PI * 2;
  return x;
}

bool inArc(flt l, flt r, flt o) {
  if (l < r) return o > l && o < r;
  if (r == 0) return o > l && o < PI * 2;
  return inArc(l, PI * 2, o) || inArc(0, r, o) || sgn(o) == 0;
}

bool ok2(const Point &A, const Point &B, const Point &O) {
  flt da = (A - O).abs(), db = (B - O).abs();
  if (sgn(da - r) != 0 || sgn(db - r) != 0) return false;
  da = fix((A - O).ang()); db = fix((B - O).ang());
  for (int i = 0; i < n; ++ i) if (!(O == P[i])) {
    if ((O - P[i]).abs() >= r * 2) continue;
    flt base = (P[i] - O).ang();
    flt a = acos((P[i] - O).abs() / 2 / r);
    flt l = fix(base + a), r = fix(base - a);
    if (inArc(da, db, l) || inArc(da, db, r)) return false;
  }
  return true;
}

int main() {
  while (scanf("%d", &n) == 1) {
    scanf("%lf%lf", &T.x, &T.y);
    O.x = O.y = 0; pt.clear();
    for (int i = 0; i < n; ++ i) scanf("%lf%lf", &P[i].x, &P[i].y);
    pt.push_back(O); pt.push_back(T);
    for (int i = 0; i < n; ++ i) {
      for (int j = i + 1; j < n; ++ j) {
        getCirCir(P[i], P[j]);
      }
      getPtsCir(O, P[i]);
      getPtsCir(T, P[i]);
    }
    sort(pt.begin() + 2, pt.end());
    pt.erase(unique(pt.begin() + 2, pt.end()), pt.end());
    vector<Point> tp;
    for (auto &p: pt) {
      flt mx(r);
      for (int i = 0; i < n; ++ i) mx = min(mx, (p - P[i]).abs());
      if (sgn(mx - r) >= 0) {
        tp.push_back(p);
      }
    }
    pt = tp;
    for (size_t i = 0; i < pt.size(); ++ i) G[i].clear();
    for (size_t i = 0; i < pt.size(); ++ i) {
      for (size_t j = 0; j < pt.size(); ++ j) {
        if (i == j) continue;
        if (ok1(pt[i], pt[j])) {
          G[i].push_back(PID(j, (pt[i] - pt[j]).abs()));
        }   
        for (int k = 0; k < n; ++ k) {
          if (ok2(pt[i], pt[j], P[k])) {
            flt ai = (pt[i] - P[k]).ang();
            flt aj = (pt[j] - P[k]).ang();
            flt da = fix(aj - ai);
            G[i].push_back(PID(j, da * r));
            G[j].push_back(PID(i, da * r));
          }
        }
      }
    }
    n = pt.size();
    vector<flt> dis(n, inf);
    vector<bool> vis(n, 0);
    queue<int> Q; Q.push(0);
    vis[0] = 1; dis[0] = 0;
    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      vis[u] = 0;
      for (auto &x: G[u]) {
        int v = x.first; flt w = x.second;
        if (sgn(dis[v] - dis[u] - w) > 0) {
          dis[v] = dis[u] + w;
          if (!vis[v]) vis[v] = 1, Q.push(v);
        }
      }
    }
    if (dis[1] == inf) puts("0.0");
    else printf("%.10f\n", dis[1]);
  }
  return 0;
}
