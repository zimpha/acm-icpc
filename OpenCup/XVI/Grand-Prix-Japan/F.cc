#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200 + 10, MAXP = 1000 + 10;

struct Edge {
  int v, d, r;
};

double dp[MAXP][MAXN], rt[MAXN];
vector<Edge> G[MAXN];
int N, M, P;

void upd(double &x, double y) {
  if (x < y) x = y;
}

int main() {
  scanf("%d%d%d", &N, &M, &P);
  for (int i = 0; i <= P; ++ i) {
    for (int j = 0; j < N; ++ j) {
      dp[i][j] = -1; rt[j] = 0;
    }
  }
  for (int i = 0; i < M; ++ i) {
    int s, t, v, d; scanf("%d%d%d%d", &s, &t, &d, &v);
    -- s; -- t;
    rt[s] = max(rt[s], 1.0 * v / d);
    rt[t] = max(rt[t], 1.0 * v / d);
    G[s].push_back((Edge){t, d, v});
    G[t].push_back((Edge){s, d, v});
  }
  dp[0][0] = 0;
  for (int i = 0; i <= P; ++ i) {
    for (int u = 0; u < N; ++ u) if (dp[i][u] > -0.1) {
      upd(dp[i + 1][u], dp[i][u] + rt[u]);
      for (auto &x: G[u]) {
        int v = x.v, d = x.d;
        if (i + d <= P) upd(dp[i + d][v], dp[i][u] + x.r);
      }
    }
  }
  printf("%.10f\n", dp[P][0]);
  return 0;
}
