#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;
int C[MAXN][MAXN];
int l[MAXN], r[MAXN];
int vis[MAXN], n;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      l[i] = 1; r[i] = n - 1; vis[i] = 0;
      for (int j = 0; j < n; ++ j) {
        scanf("%d", &C[i][j]);
        C[i][j] --;
      }
    }
    for (int cnt = 1; cnt < n; ++ cnt) {
      for (int i = 0; i < n; ++ i) if (!vis[i]) {
        while (l[i] <= r[i] && vis[C[i][r[i]]]) -- r[i];
        assert(l[i] <= r[i]);
        int u = C[i][r[i] --]; vis[u] = 1;
        while (l[u] <= r[u] && vis[C[u][l[u]]]) ++ l[u];
        int v = C[u][l[u] ++];
        printf("%d %d\n", u + 1, v + 1);
        break;
      }
    }
    puts("");
  }
  return 0;
}
