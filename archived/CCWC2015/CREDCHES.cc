#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int sx, sy, ex, ey;
int dis[8][8];

const int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
const int dy[] = {-1, 1, -1, 1, -2, 2, -2, 2};

int solve() {
  queue<PII> Q; Q.push(PII(sx, sy));
  memset(dis, -1, sizeof(dis));
  dis[sx][sy] = 0;
  while (!Q.empty()) {
    PII u = Q.front(); Q.pop();
    int x = u.first, y = u.second;
    if (x == ex && y == ey) return dis[ex][ey];
    for (int i = 0; i < 8; ++ i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx > 7 || yy < 0 || yy > 7 || dis[xx][yy] != -1) continue;
      if ((xx == ex && yy != ey) || (xx != ex && yy == ey)) continue;
      dis[xx][yy] = dis[x][y] + 1;
      Q.push(PII(xx, yy));
    }
  }
  return 0;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    printf("%d\n", solve());
  }
  return 0;
}

