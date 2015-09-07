#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<PII> State;

map<State, int> mp;
char g[20][20];
int n, m, lim;

void ins(queue<State> &Q, State &s, int step) {
  sort(s.begin() + 1, s.end());
  if (!mp.count(s)) {
    mp[s] = step;
    Q.push(s);
  }
}

void move(State &s, int i, int dx, int dy) {
  int x = s[i].first + dx, y = s[i].second + dy;
  for (; x >= 0 && x < n && y >= 0 && y < m; x += dx, y += dy) {
    if (g[x][y] == 'W') break;
    bool flag(true);
    for (size_t j = 0; j < s.size(); ++ j) {
      if (i != j && s[j].first == x && s[j].second == y) {
        flag = false;
      }
    }
    if (!flag) break;
  }
  s[i] = PII(x - dx, y - dy);
}

int solve(vector<PII> &s) {
  const int dx[] = {0, 0, 1, -1};
  const int dy[] = {1, -1, 0, 0};
  queue<vector<PII> > Q;
  mp.clear(); ins(Q, s, 0);
  while (!Q.empty()) {
    State now = Q.front(); Q.pop();
    int step = mp[now];
    if (g[now[0].first][now[0].second] == 'X') return step;
    if (step == lim) continue;
    for (size_t i = 0; i < now.size(); ++ i) {
      for (int j = 0; j < 4; ++ j) {
        State tmp = now;
        move(tmp, i, dx[j], dy[j]);
        ins(Q, tmp, step + 1);
      }
    }
  }
  return -1;
}

int main() {
  while (scanf("%*d%d%d%d", &m, &n, &lim) == 3) {
    State s(1);
    for (int i = 0; i < n; ++ i) {
      scanf("%s", g[i]);
      for (int j = 0; j < m; ++ j) {
        if (g[i][j] >= '1' && g[i][j] <= '4') {
          if (g[i][j] == '1') s[0].first = i, s[0].second = j;
          else s.push_back(PII(i, j));
        }
      }
    }
    int ret = solve(s);
    if (ret == -1 || ret > lim) puts("NO SOLUTION");
    else printf("%d\n", ret);
  }
  return 0;
}

