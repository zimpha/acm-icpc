#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 500 + 10, inf = 1e9;

bool vis[MAXN][MAXN][4];
int dis[MAXN][MAXN][4];
int grid[MAXN][MAXN];
int n, m, sx, sy, ex, ey;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int solve1() {
  queue<PII> Q; Q.push(PII(sx, sy));
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      dis[i][j][0] = inf;
      vis[i][j][0] = 0;
    }
  }
  dis[sx][sy][0] = grid[sx][sy];
  vis[sx][sy][0] = 1;
  while (!Q.empty()) {
    int x = Q.front().first, y = Q.front().second;
    vis[x][y][0] = 0; Q.pop();
    for (int i = 0; i < 4; ++ i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > m || grid[xx][yy] == -1) continue;
      if (dis[xx][yy][0] > dis[x][y][0] + grid[xx][yy]) {
        dis[xx][yy][0] = dis[x][y][0] + grid[xx][yy];
        if (!vis[xx][yy][0]) vis[xx][yy][0] = 1, Q.push(PII(xx, yy));
      }
    }
  }
  if (dis[ex][ey][0] == inf) return -1;
  else return dis[ex][ey][0];
}

struct Node {
  int x, y, d;
  Node() {}
  Node(int x, int y, int d): x(x), y(y), d(d) {}
};

int solve2() {
  queue<Node> Q;
  for (int i = 1; i <= n; ++ i) {
    for (int j = 1; j <= m; ++ j) {
      for (int k = 0; k < 4; ++ k) {
        dis[i][j][k] = inf;
        vis[i][j][k] = 0;
      }
    }
  }
  for (int k = 0; k < 4; ++ k) {
    Q.push(Node(sx, sy, k));
    dis[sx][sy][k] = grid[sx][sy];
    vis[sx][sy][k] = 1;
  }
  while (!Q.empty()) {
    Node nw = Q.front(); Q.pop();
    vis[nw.x][nw.y][nw.d] = 0;
    for (int i = 0; i < 4; ++ i) if (i != nw.d) {
      int x = nw.x + dx[i], y = nw.y + dy[i];
      if (x < 1 || x > n || y < 1 || y > m || grid[x][y] == -1) continue;
      if (dis[x][y][i] > dis[nw.x][nw.y][nw.d] + grid[x][y]) {
        dis[x][y][i] = dis[nw.x][nw.y][nw.d] + grid[x][y];
        if (!vis[x][y][i]) vis[x][y][i] = 1, Q.push(Node(x, y, i));
      }
    }
  }
  int ret(inf);
  for (int k = 0; k < 4; ++ k) ret = min(ret, dis[ex][ey][k]);
  if (ret == inf) return -1;
  else return ret;
}

int main() {
  for (int cas(1); scanf("%d%d%d%d%d%d", &n, &m, &sx, &sy, &ex, &ey) == 6; ++ cas) {
    for (int i = 1; i <= n; ++ i) {
      for (int j = 1; j <= m; ++ j) {
        char s[10]; scanf("%s", s);
        if (s[0] == '*') grid[i][j] = -1;
        else sscanf(s, "%d", &grid[i][j]);
      }
    }
    printf("Case %d: %d %d\n", cas, solve1(), solve2());
  }
  return 0;
}
