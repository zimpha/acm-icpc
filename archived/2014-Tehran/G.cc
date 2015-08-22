#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 300 + 10;

vector<int> G[MAXN];
vector<PII> has[MAXN];
vector<PII> dra;
bool vis[MAXN];
int N, M, K;

void dfs(int u) {
  for (auto &x: has[u]) dra.push_back(x);
  vis[u] = true;
  for (auto &v: G[u]) if (!vis[v]) dfs(v);
}

int main() {
  while (scanf("%d%d%d", &N, &M, &K) == 3 && N) {
    for (int i = 1; i <= N; ++ i) {
      G[i].clear(); has[i].clear();
      vis[i] = 0;
    }
    for (int i = 0; i < M; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    for (int i = 0; i < K; ++ i) {
      int c, s, h; scanf("%d%d%d", &c, &s, &h);
      has[c].push_back(PII(-h, s));
    }
    int ret(0);
    for (int i = 1; i <= N; ++ i) if (!vis[i]) {
      dra.clear(); dfs(i);
      sort(dra.begin(), dra.end());
      int s(0), mx = 1e9;
      for (auto &x: dra) {
        int need = -x.first + 1;
        mx = min(mx, max(need, s));
        s += x.second;
      }
      mx = min(mx, s);
      ret += mx;
    }
    printf("%d\n", ret);
  }
  return 0;
}
