#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 1000 + 10, MAXM = 250000 + 10;
const int MAXQ = 300, MOD = 1e9 + 7;

int f[MAXQ][MAXQ], g[MAXQ][MAXQ];
int sf[MAXM], sg[MAXM], n, t, m;
int q[MAXN], x[MAXN], id[MAXM];

int main() {
  freopen("kebab.in", "r", stdin);
  freopen("kebab.out", "w", stdout);
  scanf("%d%d", &n, &t); ++ t; m = 0;
  id[0] = 0; q[0] = 1; x[0] = 0;
  for (int i = 1; i <= n; ++ i) {
    scanf("%d%d", q + i, x + i);
    x[i] = q[i] - x[i];
    for (int j = 0; j < q[i]; ++ j) id[++ m] = i;
  }
  g[0][0] = 1; sg[0] = 1;
  for (int i = 1; i <= m; ++ i) {
    int idx = i % MAXQ;
    memset(f[idx], 0, sizeof(f[idx]));
    memset(g[idx], 0, sizeof(g[idx]));
    int now = id[i], tt = max(0, i - t);
    int pidx = tt % MAXQ;
    if (id[tt] == now) {
      for (int j = 1; j <= x[now]; ++ j) {
        f[idx][j] = (f[pidx][j - 1] + g[pidx][j - 1]) % MOD;
      }
    }
    else f[idx][1] = (sf[tt] + sg[tt]) % MOD;
    tt = i - 1; pidx = tt % MAXQ;
    if (id[tt] == now) {
      for (int j = 0; j <= x[now]; ++ j) {
        g[idx][j] = (g[pidx][j] + f[pidx][j]) % MOD;
      }
    }
    else g[idx][0] = (sf[tt] + sg[tt]) % MOD;
    for (int j = 0; j <= x[now]; ++ j) {
      sg[i] = (sg[i] + g[idx][j]) % MOD;
      sf[i] = (sf[i] + f[idx][j]) % MOD;
    }
  }
  printf("%d\n", (sf[m] + sg[m]) % MOD);
  return 0;
}

