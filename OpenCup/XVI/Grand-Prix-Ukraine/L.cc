#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, double> PID;
const int MAXN = 300 + 10, SIZE = 10000 + 10, inf = 1e9;
const double eps = 1e-8;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y): x(x), y(y) {}
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  double abs() const {return hypot(x, y);}
  int det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
};

vector<PID> G[SIZE];
double val[SIZE], dp[SIZE][1 << 6];
int msk[SIZE], vis[SIZE][1 << 6];

Point lp[MAXN], sp[MAXN];
int idx[MAXN][MAXN][MAXN];
int c[MAXN], n, m, k, s;

int sgn(int x) {return x < 0 ? -1 : x > 0;}

int get(int i, int j, int k) {
  if (i > j) swap(i, j);
  if (i > k) swap(i, k);
  if (j > k) swap(j, k);
  return idx[i][j][k];
}

bool same(Point &A, Point &B, Point &C) {
  return (A - B).det(C - B) == 0;
}
bool check(Point &A, Point &B, Point &C, Point &O) {
  return sgn((B - A).det(O - A)) * sgn((C - A).det(O - A)) < 0 &&
         sgn((A - B).det(O - B)) * sgn((C - B).det(O - B)) < 0;
}

int main() {
  scanf("%d%d%d", &n, &m, &k); s = 0;
  for (int i = 0; i < n; ++ i) scanf("%d%d", &lp[i].x, &lp[i].y);
  for (int i = 0; i < n; ++ i) scanf("%d", c + i), -- c[i];
  for (int i = 0; i < m; ++ i) scanf("%d%d", &sp[i].x, &sp[i].y);
  for (int i = 0; i < m; ++ i) {
    for (int j = i + 1; j < m; ++ j) {
      for (int k = j + 1; k < m; ++ k) {
        if (same(sp[i], sp[j], sp[k])) continue;
        idx[i][j][k] = s;
        msk[s] = 0;
        G[s].clear();
        val[s] = (sp[j] - sp[i]).abs() + (sp[k] - sp[j]).abs() + (sp[i] - sp[k]).abs();
        for (int l = 0; l < n; ++ l) if (check(sp[i], sp[j], sp[k], lp[l])) {
          msk[s] |= 1 << c[l];
        }
        ++ s;
      }
    }
  }

  for (int a = 0; a < m; ++ a) {
    for (int b = a + 1; b < m; ++ b) {
      double len = (sp[a] - sp[b]).abs();
      for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < m; ++ j) {
          if (i == j || same(sp[a], sp[b], sp[i]) || same(sp[a], sp[b], sp[j])) continue;
          int u = get(a, b, i), v = get(a, b, j);
          G[u].push_back(PID(v, len));
          G[v].push_back(PID(u, len));
        }
      }
    }
  }
  n = s; s = 1 << k;
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < s; ++ j) {
      dp[i][j] = inf;
    }
  }
  queue<PII> Q;
  for (int i = 0; i < n; ++ i) {
    dp[i][msk[i]] = val[i];
    vis[i][msk[i]] = 1;
    Q.push(PII(i, msk[i]));
  }
  while (!Q.empty()) {
    int u = Q.front().first, m = Q.front().second; Q.pop();
    vis[u][m] = 0;
    for (size_t i = 0; i < G[u].size(); ++ i) {
      int v = G[u][i].first, nm = m | msk[v];
      double w = G[u][i].second;
      if (dp[v][nm] > dp[u][m] + val[v] - w * 2 + eps) {
        dp[v][nm] = dp[u][m] + val[v] - w * 2;
        if (!vis[v][nm]) vis[v][nm] = 1, Q.push(PII(v, nm));
      }
    }
  }
  double ret(inf);
  for (int i = 0; i < n; ++ i) {
    ret = min(ret, dp[i][s - 1]);
  }
  if (ret == inf) puts("-1");
  else printf("%.10f\n", ret);
  return 0;
}