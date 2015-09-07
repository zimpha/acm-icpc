#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 10000 + 10;
vector<int> G[MAXN];
int C[MAXN], n, m;
set<int> S, gcd[MAXN];

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++ i) {
      scanf("%d", C + i);
      G[i].clear(); gcd[i].clear();
    }
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v); -- u, -- v;
      G[u].push_back(v); G[v].push_back(u);
    }
    queue<PII> Q; S.clear();
    for (int i = 0; i < n; ++ i) {
      Q.push(PII(i, C[i]));
      gcd[i].insert(C[i]);
      S.insert(C[i]);
    }
    while (!Q.empty()) {
      PII x = Q.front(); Q.pop();
      int u = x.first, g = x.second;
      for (auto &v : G[u]) {
        int gg = __gcd(g, C[v]);
        if (gcd[v].count(gg)) continue;
        gcd[v].insert(gg);
        S.insert(gg);
        Q.push(PII(v, gg));
      }
    }
    printf("%d\n", (int)S.size());
  }
  return 0;
}
