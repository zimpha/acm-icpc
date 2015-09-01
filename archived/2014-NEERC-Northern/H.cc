#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2000 + 10;

struct Point {
  LL x, y, z;
  Point() {}
  Point(LL x, LL y, LL z): x(x), y(y), z(z) {}
  bool operator < (const Point &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y) || (x == rhs.x && y == rhs.y && z < rhs.z);
  }
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y, z + rhs.z);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y, z - rhs.z);
  }
  LL dot(const Point &rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
  }
  Point det(const Point &rhs) const {
    return Point(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
  }
  void read() {
    scanf("%lld%lld%lld", &x, &y, &z);
  }
};

bool inTriangle(Point &P, Point &A, Point &B, Point &C) {
  LL a = (A - P).det(B - A).z;
  LL b = (B - P).det(C - B).z;
  LL c = (C - P).det(A - C).z;
  return (a <= 0 && b <= 0 && c <= 0) || (a >= 0 && b >= 0 && c >= 0);
}

map<Point, int> CacheID;
vector<Point> pt;
vector<int> G[MAXN << 2];
Point A[MAXN], B[MAXN], C[MAXN], S, T;
int vis[MAXN], pre[MAXN];
int dis[MAXN], N;

int getID(Point &P) {
  if (CacheID.count(P)) return CacheID[P];
  CacheID[P] = pt.size(); pt.push_back(P);
  return pt.size() - 1;
}

void link(Point &A, Point &B) {
  int u = getID(A), v = getID(B);
  G[u].push_back(v); G[v].push_back(u);
}

int main() {
  freopen("hiking.in", "r", stdin);
  freopen("hiking.out", "w", stdout);
  scanf("%d", &N);
  for (int i = 0; i < N; ++ i) {
    A[i].read(); B[i].read(); C[i].read();
    link(A[i], B[i]); link(B[i], C[i]); link(C[i], A[i]);
  }
  S.read(); T.read();
  for (int i = 0; i < N; ++ i) {
    if (inTriangle(S, A[i], B[i], C[i])) {
      link(S, A[i]); link(S, B[i]); link(S, C[i]);
    }
    if (inTriangle(T, A[i], B[i], C[i])) {
      link(T, A[i]); link(T, B[i]); link(T, C[i]);
    }
  }
  N = pt.size();
  for (int i = 0; i < N; ++ i) dis[i] = 2e6;
  int st = getID(S), ed = getID(T);
  queue<int> Q; Q.push(st); dis[st] = S.z;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); vis[u] = false;
    for (auto &v : G[u]) if (dis[v] > max(pt[v].z, (LL)dis[u])) {
      dis[v] = max(pt[v].z, (LL)dis[u]); pre[v] = u;
      if (!vis[v]) vis[v] = true, Q.push(v);
    }
  }
  vector<Point> ret;
  for (int i = ed; i != st; i = pre[i]) {
    ret.push_back(pt[i]);
  }
  ret.push_back(S);
  reverse(ret.begin(), ret.end());
  printf("%d\n", (int)ret.size());
  for (auto &p : ret) printf("%lld %lld %lld\n", p.x, p.y, p.z);
  return 0;
}