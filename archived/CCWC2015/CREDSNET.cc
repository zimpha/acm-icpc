#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

vector<int> G[MAXN];
int vis[MAXN], cnt[MAXN];

int bfs(int s) {
  vector<int> Q; Q.push_back(s); vis[s] = 1;
  for (size_t i = 0; i < Q.size(); ++ i) {
    int u = Q[i];
    for (auto &v: G[u]) if (!vis[v]) {
      Q.push_back(v); vis[v] = 1;
    }
  }
  for (auto &x: Q) vis[x] = 0;
  return Q.size();
}

int main() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++ i) {
    int u, v; scanf("%d%d", &v, &u);
    G[u].push_back(v);
    cnt[u] ++;
  }
  vector<int> can, ret; m = 0;
  for (int i = 1; i <= n; ++ i) {
    int tmp = bfs(i);
    if (tmp > m) {
      m = tmp; can.clear();
      can.push_back(i);
    }
    else if (tmp == m) can.push_back(i);
  }
  m = 0;
  for (auto &x: can) {
    if (cnt[x] > m) {
      m = cnt[x];
      ret.clear();
      ret.push_back(x);
    }
    else if (cnt[x] == m) ret.push_back(x);
  }
  sort(ret.begin(), ret.end());
  for (auto &x: ret) printf("%d ", x); puts("");
  return 0;
}

