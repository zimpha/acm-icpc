#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 50000 + 10;
int X[MAXN], Y[MAXN], n;
int col[MAXN], cnt[2];
vector<int> G[MAXN];
map<PII, int> mp;

void dfs(int u, int c) {
  col[u] = c; cnt[c] ++;
  for (auto &v : G[u]) {
    if (col[v] == -1) dfs(v, c ^ 1);
  }
}

int main() {
  while (scanf("%d", &n) == 1) {
    mp.clear();
    for (int i = 0; i < n; ++ i) {
      scanf("%d%d", X + i, Y + i);
      G[i].clear(); col[i] = -1;
      mp[PII(X[i], Y[i])] = i;
    }
    for (int dx = 0; dx <= 5; ++ dx) {
      for (int dy = -5; dy <= 5; ++ dy) {
        int dd = dx * dx + dy * dy;
        if (dd == 0 || dd > 25) continue;
        for (int i = 0; i < n; ++ i) {
          int x = X[i] + dx, y = Y[i] + dy;
          if (!mp.count(PII(x, y))) continue;
          int j = mp[PII(x, y)];
          G[i].push_back(j); G[j].push_back(i);
        }
      }
    }
    int ret = 0;
    for (int i = 0; i < n; ++ i) if (col[i] == -1) {
      memset(cnt, 0, sizeof(cnt));
      dfs(i, 0);
      ret += min(cnt[0], cnt[1]);
    }
    printf("%d\n", ret);
  }
  return 0;
}
