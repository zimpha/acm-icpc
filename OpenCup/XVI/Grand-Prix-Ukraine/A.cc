#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int n, m;
vector<int> e[N];
bool vst[N];

int bfs(int x0) {
  fill_n(vst, n+n, false);
  queue<int> q;
  q.push(x0);
  vst[x0] = true;
  int ret = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    if (x < n) ++ret;
    for (auto &y: e[x]) if (!vst[y]) q.push(y), vst[y] = true;
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int x, y, i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y), --x, --y;
    e[x].push_back(y);
    e[y+n].push_back(x+n);
  }
  for (int i = 0; i < n; ++i) e[i+n].push_back(i);
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += bfs(i+n);
  printf("%d\n", ans);
}
