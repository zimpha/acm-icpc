#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 60, MAXD = 1000 + 10;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool mp[MAXN][MAXN][4];
bool vis[MAXD][MAXN][MAXN][4];
int dir[MAXD];

struct Node {
  int x, y, s, d;
  Node() {}
  Node(int x, int y, int s, int d): x(x), y(y), s(s), d(d) {}
};

int main() {
  int n, x0, y0, t;
  while (scanf("%d%d%d%d", &n, &x0, &y0, &t) == 4) {
    memset(mp, 0, sizeof(mp));
    memset(vis, 0, sizeof(vis));
    memset(dir, -1, sizeof(dir));
    for (int i = 0; i < n; ++ i) {
      int xs, ys, xe, ye; scanf("%d%d%d%d", &xs, &ys, &xe, &ye);
      if (xs == xe) {
        if (ys > ye) swap(ys, ye);
        for (int y = ys; y <= ye; ++ y) {
          if (y < ye) mp[xs][y][1] = 1;
          if (y > ys) mp[xs][y][3] = 1;
        }
      }
      else {
        if (xs > xe) swap(xs, xe);
        for (int x = xs; x <= xe; ++ x) {
          if (x < xe) mp[x][ys][0] = 1;
          if (x > xs) mp[x][ys][2] = 1;
        }
      }
    }
    int m = 0;
    for (int i = 0; i < t; ++ i) {
      int d; char op[10];
      scanf("%d%s", &d, op);
      m += d;
      if (op[0] == 'E') dir[m] = 0;
      if (op[0] == 'N') dir[m] = 1;
      if (op[0] == 'W') dir[m] = 2;
      if (op[0] == 'S') dir[m] = 3;
    }
    vector<PII> res;
    queue<Node> Q;
    Q.push(Node(x0, y0, 0, -1));
    while (!Q.empty()) {
      Node nw = Q.front(); Q.pop();
      int s = nw.s, d = nw.d, rd = d ^ 2;
      if (s == m) {
        if (d == dir[m] || (rd != dir[m] && mp[nw.x][nw.y][dir[m]])) {
          res.push_back(PII(nw.x, nw.y));
        }
        continue;
      }
      for (int i = 0; i < 4; ++ i) {
        if (i == rd || !mp[nw.x][nw.y][i]) continue;
        if (dir[s] >= 0 && i != dir[s] && nw.d != dir[s]) continue;
        int ss = s + 1, x = nw.x + dx[i], y = nw.y + dy[i];
        if (!vis[ss][x][y][i]) {
          vis[ss][x][y][i] = 1;
          Q.push(Node(x, y, ss, i));
        }
      }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (auto &p: res) {
      printf("%d %d\n", p.first, p.second);
    }
  }
  return 0;
}
