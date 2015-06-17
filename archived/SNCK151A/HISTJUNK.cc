#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200, inf = 1e9;
int g[MAXN][MAXN], a[MAXN];
int n, m;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) {
      fill_n(g[i] + 1, n, inf);
      g[i][i] = 0;
    }
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      g[u][v] = g[v][u] = 1;
    }
    for (int k = 1; k <= n; ++ k) {
      for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= k; ++ j) {
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        }
      }
    }
    for (int i = 1; i <= n; ++ i) {
      a[i] = *max_element(g[i] + 1, g[i] + 1 + n);
    }
    if (a[1] != inf && count(a + 1, a + 1 + n, a[1]) == n) {
      puts("0 0"); continue;
    }
    int t = count(a + 1, a + 1 + n, 1);
    if (t) {
      printf("%d %d\n", t + 1, n);
      for (int i = 1, c = n + 1; i <= n; ++ i) {
        if (a[i] == 1) printf("%d %d\n", ++ c, i);
        else printf("%d %d\n", n + 1, i);
      }
      continue;
    }
    printf("%d %d\n", 4, n * 2 + 2);
    printf("%d %d\n%d %d\n", n + 1, n + 3, n + 2, n + 4);
    for (int i = 1; i <= n; ++ i) {
      printf("%d %d\n%d %d\n", i, n + 1, i, n + 2);
    }
  }
  return 0;
}
