#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int mp[7][7];
int deg[7], vs[7], cc;

void dfs(int u) {
  vs[u] = 1; cc ++;
  for (int v = 0; v < 7; ++ v) {
    if (mp[u][v] && !vs[v]) dfs(v);
  }
}

int main() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int x, y; scanf("%d%d", &x, &y);
    deg[x] ++; deg[y] ++;
    mp[x][y] = mp[y][x] = 1;
  }
  int tot(0);
  for (int i = 0; i < 7; ++ i) if (deg[i]) ++ tot;
  int c(0);
  for (int i = 0; i < 7; ++ i) {
    c += deg[i] & 1;
  }
  cc = 0;
  for (int i = 0; i < 7; ++ i) if (deg[i]) {
    dfs(i);
    break;
  }
  if ((c == 0 || c == 2) && cc == tot) puts("YES");
  else puts("NO");
  return 0;
}
