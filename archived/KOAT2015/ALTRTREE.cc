#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
vector<int> G[MAXN];
int val[MAXN], isrt[MAXN];
int n;
bool dfs(int u, int s) {
  bool ret = true;
  for (int v: G[u]) {
    if (s && val[u] >= val[v]) return false;
    if (!s && val[u] <= val[v]) return false;
    ret &= dfs(v, !s);
  }
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      G[i].clear(); isrt[i] = true;
      scanf("%d", val + i);
    }
    for (int i = 0; i < n; ++ i) {
      int d; scanf("%d", &d);
      while (d --) {
        int x; scanf("%d", &x); isrt[x] = false;
        G[i].push_back(x);
      }
    }
    int rt = -1;
    for (rt = 0; rt < n && !isrt[rt]; ++ rt);
    if (dfs(rt, 1)) puts("MAT");
    else if (dfs(rt, 0)) puts("VAT");
    else puts("NAT");
  }
  return 0;
}
