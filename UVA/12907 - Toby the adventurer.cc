#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
vector<PII> G[MAXN];
map<PII, int> mp;
int vis[MAXN], N, M, R, sum;
int fa[MAXN], cost[MAXN];

void dfs(int u, int f = -1) {
  fa[u] = f; vis[u] = true;
  for (auto &x: G[u]) if (!vis[x.first]) {
    cost[x.first] = x.second; sum += x.second;
    mp[PII(u, x.first)] = x.second;
    dfs(x.first, u);
  }
}

bool is_connect() {
  for (int i = 0; i < N; ++ i) {
    if (!vis[i]) return false;
  }
  return true;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d%d%d", &N, &M, &R);
    for (int i = 0; i < N; ++ i) {
      G[i].clear(); fa[i] = -1;
      vis[i] = 0; cost[i] = 0;
    }
    static int u[MAXN], v[MAXN], w[MAXN];
    for (int i = 0; i < M; ++ i) {
      scanf("%d%d%d", u + i, v + i, w + i);
      G[u[i]].push_back(PII(v[i], w[i]));
    }
    sum = 0; mp.clear(); dfs(R);
    if (M < N - 1 || !is_connect()) puts("impossible");
    else {
      if (M == N) {
        for (int i = 0; i < M; ++ i) {
          if (mp.count(PII(u[i], v[i]))) {
            mp[PII(u[i], v[i])] = max(mp[PII(u[i], v[i])], w[i]);
          }
          else {
            if (w[i] < cost[v[i]]) {
              sum += w[i] - cost[v[i]];
              mp.erase(PII(fa[v[i]], v[i]));
              mp[PII(u[i], v[i])] = w[i];
            }
            break;
          }
        }
      }
      printf("%d\n", sum);
      for (auto &x: mp) {
        printf("%d %d %d\n", x.first.first, x.first.second, x.second);
      }
    }
  }
  return 0;
}
