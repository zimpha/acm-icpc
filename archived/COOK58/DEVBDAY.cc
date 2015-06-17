#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
static const int MAXN = 100000 + 10;

struct Tarjan {// index from 0 to n - 1
  vector<int> SCC[MAXN];
  int low[MAXN],dfn[MAXN],stk[MAXN],col[MAXN];
  int scc_cnt,sz,top;
  void dfs(int x,const vector<int> G[]) {
    low[x]=dfn[x]=++sz; stk[++top]=x;
    for (int i=0,y;i<(int)G[x].size();++i) {
      if (!dfn[y=G[x][i]]) {
        dfs(y,G); low[x]=min(low[x],low[y]);
      }
      else if (col[y]==-1) low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x]) {
      SCC[scc_cnt++].clear();
      do {
        SCC[scc_cnt-1].push_back(stk[top]);
        col[stk[top]]=scc_cnt-1;
      } while (stk[top--]!= x);
    }
  }
  void solve(int n,const vector<int> G[]) {
    sz=top=scc_cnt=0; memset(dfn,0,sizeof(dfn[0]) * n);
    memset(col,-1,sizeof(col[0]) * n);
    for (int i=0;i<n;++i) if (!dfn[i]) dfs(i,G);
  }
} AC;

LL dp[MAXN];
int val[MAXN];
vector<int> G[MAXN];

void dfs(int u, int cc) {
  dp[u] = val[u];
  for (auto &v: G[u]) if (AC.col[v] != cc) {
    dfs(v, cc);
    if (dp[v] > 0) dp[u] += dp[v];
  }
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x); -- x;
      G[x].push_back(i);
    }
    for (int i = 0; i < n; ++ i) scanf("%d", val + i);
    AC.solve(n, G);
    LL ret = 0;
    for (int i = 0; i < AC.scc_cnt; ++ i) {
      if (AC.SCC[i].size() == 1) continue;
      LL now = 0;
      for (auto &u: AC.SCC[i]) {
        dfs(u, i);
        now += dp[u];
      }
      if (now > 0) ret += now;
    }
    printf("%lld\n", ret);
  }
  return 0;
}