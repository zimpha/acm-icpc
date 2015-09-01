#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 100;
vector<int> G[MAXN];
bool isP[MAXN], D[MAXN];
int go[MAXN], label[MAXN];
vector<PII> ret;
int n, m;

void dfs(int u) {
  go[u] = 0;
  if (isP[u]) {
    go[u] = 1 << label[u];
    return;
  }
  if (G[u][0] > G[u][1]) swap(G[u][0], G[u][1]);
  D[u] = 0;
  dfs(G[u][0]); dfs(G[u][1]);
  go[u] = go[G[u][0]] | go[G[u][1]];
}

void solve(int u, int t, int ed) {
  if (isP[u]) return;
  for (int i = 0; i < 2; ++ i) {
    int v = G[u][i];
    if (go[v] >> ed & 1) {
      if (D[u] != i) {
        ret.push_back(PII(t, u));
        D[u] ^= 1;
      }
      solve(v, t + 1, ed);
      break;
    }
  }
}

int main() {
  freopen("instruction.in", "r", stdin);
  freopen("instruction.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1, q; i <= n; ++ i) {
    char op[10];
    scanf("%s", op);
    isP[i] = (op[0] == 'p');
    if (op[0] == 's') {
      scanf("%d", &q);
      G[q].push_back(i);
    }
    else {
      scanf("%d%s", &q, op);
      G[q].push_back(i);
      label[i] = op[0] - 'a';
    }
  }
  dfs(G[0][0]);
  scanf("%d", &m);
  for (int _ = 0; _ < m; ++ _) {
    char op[10];
    int t; scanf("%d%s", &t, op);
    solve(G[0][0], t + 1, op[0] - 'a');
  }
  sort(ret.begin(), ret.end());
  printf("%d\n", (int)ret.size());
  for (size_t i = 0; i < ret.size(); ++ i) {
    printf("%d %d\n", ret[i].second, ret[i].first);
  }
  return 0;
}