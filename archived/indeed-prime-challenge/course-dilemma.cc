#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
vector<int> G[MAXN];
int deg[MAXN], dp[MAXN];
int N, R;

bool solve() {
  vector<int> Q;
  for (int i = 0; i < N; ++ i) {
    if (deg[i] == 0) Q.push_back(i);
    dp[i] = deg[i] == 0;
  }
  int mx = 0;
  for (size_t i = 0; i < Q.size(); ++ i) {
    int u = Q[i]; mx = max(mx, dp[u]);
    for (auto &v: G[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
      if (-- deg[v] == 0) Q.push_back(v);
    }
  }
  if (Q.size() == N) printf("%d semester(s)\n", mx);
  return Q.size() == N;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas){
    scanf("%d%d", &N, &R);
    for (int i = 0; i < N; ++ i) {
      G[i].clear(); deg[i] = 0;
    }
    for (int i = 0; i < R; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v); deg[v] ++;
    }
    printf("Case %d: ", cas);
    if (!solve()) puts("Never Ends");
  }
  return 0;
}
