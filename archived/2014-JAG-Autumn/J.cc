#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200, MAXT = 10000 + 10;

vector<int> G[MAXN];
bool mark[MAXN];
int p[MAXN], t[MAXN], k[MAXN];
int N, M, T;

namespace SCC {
  vector<int> SCC[MAXN], SCCG[MAXN];
  int low[MAXN], dfn[MAXN], ord[MAXN];
  int scc_cnt;
  void dfs(int x) {
    static int stk[MAXN], top = 0, sz = 0;
    stk[++ top] = x; low[x] = dfn[x] = ++ sz;
    for (auto &y : G[x]) {
      if (!dfn[y]) {
        dfs(y); low[x] = min(low[x], low[y]);
      }
      else if (ord[y] == -1) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
      SCC[scc_cnt ++].clear();
      do {
        SCC[scc_cnt - 1].push_back(stk[top]);
        ord[stk[top]] = scc_cnt - 1;
      } while (x != stk[top --]);
    }
  }
  void scc() {
    memset(dfn, 0, sizeof(dfn));
    memset(ord, -1, sizeof(ord));
    scc_cnt = 0;
    for (int i = 0; i < N; ++ i) {
      if (!dfn[i]) dfs(i);
    }
  }
  void build() {
    for (int i = 0; i < scc_cnt; ++ i) {
      SCCG[i].clear();
      for (auto &u : SCC[i]) for (auto &v : G[u]) {
        if (ord[v] != ord[u]) SCCG[i].push_back(ord[v]);
      }
      sort(SCCG[i].begin(), SCCG[i].end());
      SCCG[i].resize(unique(SCCG[i].begin(), SCCG[i].end()) - SCCG[i].begin());
    }
  }
  int deg[MAXN], self[MAXN];
  int dp[MAXN][MAXT];
  void update(int x) {
    vector<PII> item;
    for (auto &u : SCC[x]) {
      for (int s = 1; s <= k[u]; s <<= 1) {
        item.push_back(PII(s * t[u], s * p[u]));
        k[u] -= s;
      }
      if (k[u]) item.push_back(PII(k[u] * t[u], k[u] * p[u]));
    }
    for (auto &v : item) {
      for (int i = T; i >= v.first; -- i) {
        dp[x][i] = max(dp[x][i], dp[x][i - v.first] + v.second);
      }
    }
  }
  int solve() {
    scc(); build();
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < scc_cnt; ++ i) {
      self[i] = (SCC[i].size() == 1 && mark[SCC[i][0]]);
      for (auto &v : SCCG[i]) deg[v] ++;
      for (int j = 0; j <= T; ++ j) dp[i][j] = 0;
    }
    queue<int> Q;
    for (int i = 0; i < scc_cnt; ++ i) {
      if (deg[i] == 0) Q.push(i);
    }
    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      if (SCC[x].size() == 1 && !self[x]) {
        int u = SCC[x][0];
        for (int j = T - t[u]; j >= 0; -- j) {
          dp[x][j + t[u]] = max(dp[x][j + t[u]], dp[x][j] + p[u]);
        }
      }
      else update(x);
      for (auto &y : SCCG[x]) {
        for (int i = 0; i <= T; ++ i) {
          dp[y][i] = max(dp[y][i], dp[x][i]);
        }
        if (-- deg[y] == 0) Q.push(y);
      }
    }
    int ret = 0;
    for (int i = 0; i < scc_cnt; ++ i) {
      for (int j = 0; j <= T; ++ j) {
        ret = max(ret, dp[i][j]);
      }
    }
    return ret;
  }
}
int main() {
  while (scanf("%d%d%d", &N, &M, &T) == 3 && N) {
    for (int i = 0; i < N; ++ i) {
      G[i].clear(); mark[i] = false;
      scanf("%d%d%d", p + i, t + i, k + i);
    }
    for (int i = 0; i < M; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      -- u, -- v; G[u].push_back(v);
      if (u == v) mark[u] = true;
    }
    printf("%d\n", SCC::solve());
  }
  return 0;
}