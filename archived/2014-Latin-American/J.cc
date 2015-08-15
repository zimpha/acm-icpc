#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500 + 10;

int R[MAXN][MAXN], V[MAXN][MAXN], C[MAXN][MAXN];
int n, m, q;

struct Node {
  int x, y, v;
  Node() {}
  Node(int a, int b, int c): x(a), y(b), v(c) {}
  bool operator < (const Node &rhs) const {
    return v > rhs.v;
  }
};

struct BIT : priority_queue<Node> {
  int u[MAXN][MAXN], r, c;
  void init(int n, int m) {
    this->r = n; this->c = m;
    memset(u, 0, sizeof(u));
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        upd(i, j, 1);
      }
    }
    while (!empty()) pop();
  }
  void upd(int x, int y, int v) {
    for (int i = x; i <= r; i += i & -i) {
      for (int j = y; j <= c; j += j & -j) {
        u[i][j] += v;
      }
    }
  }
  int get(int x, int y) {
    int r = 0;
    for (int i = x; i; i -= i & -i) {
      for (int j = y; j; j -= j & -j) {
        r += u[i][j];
      }
    }
    return r;
  }
  int get(int x1, int y1, int x2, int y2) {//x1 <= x2, y1 <= y2
    return get(x2, y2) + get(x1 - 1, y1 - 1) - get(x2, y1 - 1) - get(x1 - 1, y2);
  }
  void cover(int x1, int y1, int x2, int y2, int cost, int tot) {
    if (tot == 0) return;
    int mx = (x1 + x2) >> 1, my = (y1 + y2) >> 1;
    if (x1 == x2) {
      if (y1 == y2) {
        push(Node(x1, y1, cost + V[x1][y1]));
        upd(x1, y1, -1);
        return;
      }
      int cnt = get(x1, y1, x2, my);
      if (cnt) cover(x1, y1, x2, my, cost, cnt);
      if (tot > cnt) cover(x1, my + 1, x2, y2, cost, tot - cnt);
    }
    else {
      int cnt = get(x1, y1, mx, y2);
      if (cnt) cover(x1, y1, mx, y2, cost, cnt);
      if (tot > cnt) cover(mx + 1, y1, x2, y2, cost, tot - cnt);
    }
  }
} AC;

int dijkstra(int sx, int sy, int ex, int ey) {
  if (sx == ex && sy == ey) return 0;
  AC.init(n, m); AC.upd(sx, sy, -1);
  AC.push(Node(sx, sy, V[sx][sy]));
  while (!AC.empty()) {
    Node u = AC.top(); AC.pop();
    int r = R[u.x][u.y], c = C[u.x][u.y];
    if (abs(u.x - ex) <= r && abs(u.y - ey) <= c) return u.v;
    int x1 = max(1, u.x - r), x2 = min(n, u.x + r);
    int y1 = max(1, u.y - c), y2 = min(m, u.y + c);
    AC.cover(x1, y1, x2, y2, u.v, AC.get(x1, y1, x2, y2));
  }
  return -1;
}

int main() {
  while (scanf("%d%d%d", &n, &m, &q) == 3) {
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        scanf("%d", &V[i][j]);
      }
    }
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        scanf("%d", &R[i][j]);
      }
    }
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        scanf("%d", &C[i][j]);
      }
    }
    int sx, sy; scanf("%d%d", &sx, &sy);
    for (int i = 1; i < q; ++ i) {
      int ex, ey; scanf("%d%d", &ex, &ey);
      if (i > 1) putchar(' ');
      printf("%d", dijkstra(sx, sy, ex, ey));
      sx = ex; sy = ey;
    }
    puts("");
  }
  return 0;
}