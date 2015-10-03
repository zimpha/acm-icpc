#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000 + 10;
typedef pair<int, int> PII;

string s[MAXN];
bool vis[MAXN];
int n, m;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int bfs(int x, int y) {
  queue<PII> Q; Q.push(PII(x, y));
  vis[x * m + y] = 1; int ret(0);
  while (!Q.empty()) {
    x = Q.front().first, y = Q.front().second; Q.pop();
    ret ++;
    for (int i = 0; i < 4; ++ i) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
      if (vis[xx * m + yy] || s[xx][yy] == '#') continue;
      vis[xx * m + yy] = 1; Q.push(PII(xx, yy));
    }
  }
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
      static char buf[MAXN]; scanf("%s", buf);
      s[i] = buf;
    }
    memset(vis, 0, sizeof(vis));
    vector<int> pt;
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < m; ++ j) if (!vis[i * m + j] && s[i][j] == 'o') {
        pt.push_back(bfs(i, j));
      }
    }
    double ret(1);
    for (size_t i = 1; i < pt.size(); ++ i) {
      ret += pt[i] * 1.0 / (pt[i] + pt[0]);
    }
    printf("%.10f\n", ret);
  }
  return 0;
}
