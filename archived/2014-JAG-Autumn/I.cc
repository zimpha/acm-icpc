#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
  bool operator != (const Point &rhs) const {
    return x != rhs.x || y != rhs.y;
  }
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  Point operator * (const int k) const {
    return Point(x * k, y * k);
  }
  int det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
  int dot(const Point &rhs) const {
    return x * rhs.x + y * rhs.y;
  }
};

bool onSeg(Point &A, Point &B, Point &O) {// O on AB
  return (A - O).det(B - O) == 0 && (A - O).dot(B - O) <= 0;
}

bool has_common(Point A, Point B, Point C, Point D) {
  if (!((B - A).det(C - A) == 0 && (B - A).det(D - A) == 0)) return false;
  if ((B - A).dot(D - C) > 0) swap(C, D);
  assert((B - A).dot(D - C) < 0);
  if (onSeg(A, B, C) && onSeg(A, B, D)) return true;
  if (onSeg(C, D, A) && onSeg(C, D, B)) return true;
  if (onSeg(A, B, D) && onSeg(C, D, B) && B != D) return true;
  if (onSeg(C, D, A) && onSeg(A, B, C) && A != C) return true;
  return false;
}

const int MAXN = 50;
vector<Point> poly[MAXN];
vector<int> G[MAXN];
int n;

bool check(vector<Point> &A, vector<Point> &B) {
  for (size_t i = 0; i + 1 < A.size(); ++ i) {
    for (size_t j = 0; j + 1 < B.size(); ++ j) {
      if (has_common(A[i], A[i + 1], B[j], B[j + 1])) return true;
    }
  }
  return false;
}

int col[MAXN], mark[MAXN];

bool dfs(int u, int c) {
  if (col[u] != -1) return col[u] == c;
  col[u] = c;
  for (auto &v : G[u]) if (mark[v]) {
    if (!dfs(v, c ^ 1)) return false;
  }
  return true;
}
bool bipartite() {
  for (int i = 0; i < n; ++ i) col[i] = -1;
  for (int i = 0; i < n; ++ i) {
    if (col[i] == -1 && mark[i]) {
      if (!dfs(i, 0)) return false;
    }
  }
  return true;
}

typedef unsigned long long ULL;
int trail_zero(ULL s) {
  return s ? __builtin_ctzll(s) : 64;
}
bool BronKerbosch(const vector<ULL> &g, ULL cur, ULL allow, ULL forbid) {
  if (allow == 0 && forbid == 0) {
    for (int i = 0; i < n; ++ i) mark[i] = !(cur >> i & 1);
    return bipartite();
  }
  if (allow == 0) return false;
  int pivot = trail_zero(allow | forbid);
  ULL z = allow & ~g[pivot];
  for (size_t u = trail_zero(z); u < g.size(); u += trail_zero(z >> (u + 1)) + 1) {
    if (BronKerbosch(g, cur | (1ULL << u), allow & g[u], forbid & g[u])) return true;
    allow ^= 1ULL << u; forbid |= 1ULL << u;
  }
  return false;
}

bool tricolor() {
  vector<ULL> g(n, 0);
  for (int i = 0; i < n; ++ i) g[i] = (1ULL << n) - 1 - (1ULL << i);
  for (int i = 0; i < n; ++ i) {
    for (auto &j : G[i]) g[i] ^= 1ULL << j;
  }
  return BronKerbosch(g, 0, (1ULL << n) - 1, 0);
}

int solve() {
  bool flag = true;
  for (int i = 0; i < n; ++ i) flag &= G[i].empty();
  for (int i = 0; i < n; ++ i) mark[i] = 1;
  if (flag) return 1;
  else if (bipartite()) return 2;
  else if (tricolor()) return 3;
  else return 4;
}

int main() {
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; ++ i) {
      int m; scanf("%d", &m);
      poly[i].clear(); G[i].clear();
      for (int _ = 0; _ < m; ++ _) {
        int x, y; scanf("%d%d", &x, &y);
        poly[i].push_back(Point(x, y));
      }
      poly[i].push_back(poly[i][0]);
    }
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < i; ++ j) {
        if (check(poly[i], poly[j])) {
          G[i].push_back(j);
          G[j].push_back(i);
        }
      }
    }
    printf("%d\n", solve());
  }
  return 0;
}