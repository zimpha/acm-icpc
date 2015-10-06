#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
vector<int> G[MAXN], adj[MAXN];
int c[MAXN], deg[MAXN], dp[MAXN];
int dsu[MAXN], sz[MAXN], N, M;

bool cmp(int a, int b) {
  return c[a] < c[b];
}

int get(int x) {
  if (x != dsu[x]) dsu[x] = get(dsu[x]);
  return dsu[x];
}
void mer(int x, int y) {
  x = get(x), y = get(y);
  if (x != y) dsu[x] = y, sz[y] += sz[x];
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++ i) {
    scanf("%d", c + i);
    dsu[i] = i; sz[i] = 1;
  }
  scanf("%d", &M);
  for (int i = 0; i < M; ++ i) {
    int u, v; scanf("%d%d", &u, &v);
    -- u, -- v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (c[u] == c[v]) mer(u, v);
  }
  for (int u = 0; u < N; ++ u) {
    sort(adj[u].begin(), adj[u].end(), cmp);
    for (size_t i = 1; i < adj[u].size(); ++ i) {
      if (c[adj[u][i - 1]] == c[adj[u][i]]) {
        mer(adj[u][i - 1], adj[u][i]);
      }
    }
  }
  for (int u = 0; u < N; ++ u) {
    for (auto &v: adj[u]) {
      int x = get(u), y = get(v);
      if (c[x] > c[y]) swap(x, y);
      if (c[x] < c[y]) {
        G[x].push_back(y);
        deg[y] ++;
      }
    }
    for (size_t i = 1; i < adj[u].size(); ++ i) {
      int x = get(adj[u][i - 1]), y = get(adj[u][i]);
      if (c[x] > c[y]) swap(c[x], c[y]);
      if (c[x] < c[y]) {
        G[x].push_back(y);
        deg[y] ++;
      }
    }
  }
  queue<int> Q;
  for (int i = 0; i < N; ++ i) {
    if (get(i) == i && deg[i] == 0) {
      Q.push(i); dp[i] = 1;
    }
  }
  LL ret(0);
  while (!Q.empty()) {
    int u = Q.front(); Q.pop();
    ret += (LL)dp[u] * sz[u];
    for (auto &v: G[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
      if (-- deg[v] == 0) Q.push(v);
    }
  }
  cout << ret << endl;
  return 0;
}
