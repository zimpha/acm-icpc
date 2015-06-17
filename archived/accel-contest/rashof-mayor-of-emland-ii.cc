#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

int sz[MAXN], S, n;
vector<int> G[MAXN];
vector<LL> X;

void dfs(int u, int f = -1) {
  sz[u] = 1;
  for (auto &v: G[u]) if (v != f) {
    dfs(v, u); sz[u] += sz[v];
    X.push_back((LL)sz[v] * (n - sz[v]));
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n); S = 0;
    if (n == 1) {puts("0"); continue;}
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w);
      G[u].push_back(v); G[v].push_back(u);
      S += w;
    }
    X.clear();
    dfs(1);
    sort(X.begin(), X.end());
    LL r = X[0] * (S - (n - 2));
    for (int i = 1; i < n - 1; ++ i) r += X[i];
    cout << r << endl;
  }
  return 0;
}

