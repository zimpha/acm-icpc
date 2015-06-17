#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1000 + 10;
vector<int> G[MAXN], pt[MAXN];
int A[MAXN][MAXN], col[MAXN];
int dp[MAXN][MAXN];
PII blk[MAXN];
int N, M;

bool dfs(int u, int c) {
  if (col[u] != -1) return col[u] == c;
  col[u] = c; pt[M].push_back(u);
  if (c) blk[M].second ++;
  else blk[M].first ++;
  for (auto &v: G[u]) {
    if (!dfs(v, c ^ 1)) return false;
  }
  return true;
}

void change(int n, int s) {
  if (n == 0 && s == 0) return;
  if (s >= blk[n].first && dp[n - 1][s - blk[n].first]) {
    change(n - 1, s - blk[n].first);
    return;
  }
  if (s >= blk[n].second && dp[n - 1][s - blk[n].second]) {
    s -= blk[n].second;
    for (auto &u: pt[n]) col[u] ^= 1;
    change(n - 1, s);
    return;
  }
  assert(false);
}

bool solve() {
  for (int i = 0; i < N; ++ i) {
    if (col[i] == -1) {
      M ++;
      pt[M].clear(); blk[M] = PII(0, 0);
      if (!dfs(i, 0)) return false;
    }
  }
  for (int i = 0; i <= N; ++ i) {
    for (int j = 0; j <= N; ++ j) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= M; ++ i) {
    for (int j = 0; j <= N; ++ j) {
      if (j >= blk[i].first) dp[i][j] |= dp[i - 1][j - blk[i].first];
      if (j >= blk[i].second) dp[i][j] |= dp[i - 1][j - blk[i].second];
    }
  }
  int mx = 0, L = 0;
  for (int i = 0; i <= N; ++ i) {
    if (dp[M][i] && i * (N - i) > mx) {
      L = i; mx = i * (N - i);
    }
  }
  change(M, L);
  for (int i = 0; i < N; ++ i) printf("%d ", col[i]); puts("");
  return true;
}

int main () {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &N); M = 0;
    for (int i = 0; i < N; ++ i) {
      G[i].clear();
      col[i] = -1;
    }
    for (int i = 0; i < N; ++ i) {
      for (int j = 0; j < N; ++ j) {
        scanf("%d", &A[i][j]);
        if (A[i][j] == 1) {
          G[i].push_back(j);
          G[j].push_back(i);
        }
      }
    }
    if (!solve()) puts("-1");
  }
  return 0;
}
