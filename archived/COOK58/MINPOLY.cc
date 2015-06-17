#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100, inf = 1e9;
struct Point {
  LL x, y;
  Point() {}
  Point(LL x, LL y): x(x), y(y) {}
  bool operator < (const Point &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
  Point operator + (const Point &rhs) const {
    return Point(x + rhs.x, y + rhs.y);
  }
  Point operator - (const Point &rhs) const {
    return Point(x - rhs.x, y - rhs.y);
  }
  LL dot(const Point &rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  LL det(const Point &rhs) const {
    return x * rhs.y - y * rhs.x;
  }
} O, P[MAXN];

bool acmp(const Point &A, const Point &B) {
  return (A - O).det(B - O) > 0;
}

map<Point, int> val;
int dp[MAXN][MAXN][MAXN];
int cf[MAXN][MAXN][MAXN];
int ret[MAXN], n, m;

int main() {
  scanf("%d", &n);
  for (int i = 0, b; i < n; ++ i) {
    scanf("%lld%lld%d", &P[i].x, &P[i].y, &b);
    val[P[i]] = b;
  }
  for (int i = 0; i <= n; ++ i) ret[i] = inf;
  for (int st = 0; st < n; ++ st) {
    vector<Point> pt; O = P[st];
    for (int i = 0; i < n; ++ i) {
      if (P[i].y > O.y || (P[i].y == O.y && P[i].x > O.x)) {
        pt.push_back(P[i]);
      }
    }
    sort(pt.begin(), pt.end(), acmp);
    pt.push_back(O); m = pt.size();
    for (int i = 0; i <= m; ++ i) {
      for (int j = 0; j <= m; ++ j) {
        for (int k = 0; k <= m; ++ k) {
          cf[i][j][k] = dp[i][j][k] = inf;
        }
      }
    }
    for (int i = 0; i + 1 < m; ++ i) {
      for (int j = i + 1; j + 1 < m; ++ j) {
        dp[i][j][2] = 0;
        for (int k = 0; k < m; ++ k) {
          if ((pt[k] - pt[i]).det(O - pt[i]) >= 0 && (pt[k] - pt[i]).det(pt[j] - pt[i]) <= 0) {
            dp[i][j][2] += val[pt[k]];
          }
        }
      }
    }
    for (int i = 0; i < m; ++ i) {
      for (int j = i + 1; j < m; ++ j) {
        for (int k = j + 1; k < m; ++ k) {
          if ((pt[j] - pt[i]).det(pt[k] - pt[j]) > 0) {
            cf[i][j][k] = 0;
            for (int l = 0; l < m; ++ l) {
              if ((pt[l] - pt[j]).det(pt[k] - pt[j]) > 0 && (pt[l] - pt[j]).det(pt[j] - pt[i]) < 0) {
                cf[i][j][k] += val[pt[l]];
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < m; ++ i) {
      for (int j = i + 1; j < m; ++ j) {
        for (int k = 0; k < m; ++ k) if (dp[i][j][k] < inf) {
          for (int l = j + 1; l < m; ++ l) {
            if ((pt[j] - pt[i]).det(pt[l] - pt[j]) > 0) {
              dp[j][l][k + 1] = min(dp[j][l][k + 1], dp[i][j][k] - cf[i][j][l]);
            }
          }
        }
      }
    }
    for (int i = 0; i + 1 < m; ++ i) {
      for (int j = 0; j <= m; ++ j) {
        ret[j] = min(ret[j], dp[i][m - 1][j]);
      }
    }
  }
  for (int i = 3; i <= n; ++ i) {
    if (ret[i] == inf) cout << "-1" << " ";
    else cout << ret[i] << " ";
  }
  cout << endl;
  return 0;
}