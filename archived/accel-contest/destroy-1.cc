#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 20;

int dsu[MAXN], dp[1 << 20], ok[1 << 20];
PII e[200];
int n, m;

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}

int solve(int msk) {
  if (dp[msk] != -1) return dp[msk];
  if (__builtin_popcount(msk) == 1 || !ok[msk]) return dp[msk] = 1;
  dp[msk] = 0;
  for (int i = 0; i < n; ++ i) if (msk >> i & 1) {
    if (solve(msk ^ (1 << i)) == 0) dp[msk] = 1;
  }
  return dp[msk];
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      e[i] = PII(u - 1, v - 1);
    }
    int s = 1 << n;
    for (int msk = 0; msk < s; ++ msk) {
      dp[msk] = -1; ok[msk] = 0;
      int c = __builtin_popcount(msk);
      for (int i = 0; i < n; ++ i) dsu[i] = i;
      for (int i = 0; i < m && c != 1; ++ i) {
        if ((msk >> e[i].first & 1) && (msk >> e[i].second & 1)) {
          int u = get(e[i].first), v = get(e[i].second);
          if (u != v) dsu[u] = v, -- c;
        }
      }
      ok[msk] = c == 1;
    }
    if (solve(s - 1)) puts("Artur");
    else puts("Alex");
  }
  return 0;
}

