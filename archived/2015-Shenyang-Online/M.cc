#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef double flt;

const int MAXN = 200, MAXM = 2000 + 10;
const flt eps = 1e-9;

struct Point{
  flt x,y;
  Point(){}
  Point(flt _x,flt _y):x(_x),y(_y){}
  Point operator * (const flt k) const {
    return Point(x * k, y * k);
  }
  Point operator / (const flt k) const {
    return Point(x / k, y / k);
  }
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
} p[MAXN], q[MAXN];
int np;


int signum(flt x) {
  if (x < -eps) return -1;
  else return x > eps;
}

inline Point intersect(Point x,Point y,flt a,flt b,flt c){
  flt u = fabs(a * x.x + b * x.y + c);
  flt v = fabs(a * y.x + b * y.y + c);
  return Point((x.x * v + y.x * u) / (u + v) , (x.y * v + y.y * u) / (u + v) );
}

inline void cut(flt a,flt b ,flt c){
  int curCnt = 0;
  p[np + 1] = p[1]; p[0] = p[np];
  for(int i = 1; i <= np; ++i){
    if(signum(a*p[i].x + b*p[i].y + c) >= 0)q[++curCnt] = p[i];
    else {
      if(signum(a*p[i-1].x + b*p[i-1].y + c) > 0) {
        q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
      }
      if(signum(a*p[i+1].x + b*p[i+1].y + c) > 0){
        q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
      }
    }
  }
  for (int i = 1; i <= curCnt; ++ i) p[i] = q[i];
  np = curCnt;
}

LL sx[MAXN], sy[MAXN];
LL sx2[MAXN], sy2[MAXN];
int n, m;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
      sx[i] = sy[i] = 0;
      sx2[i] = sy2[i] = 0;
      for (int j = 0; j < m; ++ j) {
        int x, y; scanf("%d%d", &x, &y);
        sx[i] += x * 2; sy[i] += y * 2;
        sx2[i] += x * x; sy2[i] += y * y;
      }
    }
    printf("Case #%d:", cas);
    for (int a = 0; a < n; ++ a) {
      np = 4;
      p[1] = Point(0, 0);
      p[2] = Point(4095, 0);
      p[3] = Point(4095, 4095);
      p[4] = Point(0, 4095);
      for (int b = 0; b < n; ++ b) if (a != b) {
        LL A = sx[a] - sx[b], B = sy[a] - sy[b];
        LL C = sx2[b] + sy2[b] - sx2[a] - sy2[a];
        cut(A, B, C);
      }
      flt area(0);
      p[np + 1] = p[1];
      for (int i = 1; i <= np; ++ i) {
        area += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
      }
      area /= 2; if (area < 0) area = -area;
      printf(" %.0f", area + eps);
    }
    puts("");
  }
  return 0;
}