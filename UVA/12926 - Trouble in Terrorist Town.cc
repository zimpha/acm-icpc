#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

static const int MAXN = 5000 + 10;
bool G[MAXN][MAXN];
int n, m;

struct Tarjan {// index from 0 to n - 1
  int low[MAXN],dfn[MAXN],stk[MAXN],col[MAXN];
  int scc_cnt,sz,top;
  void dfs(int x, const bool G[][MAXN]) {
    low[x]=dfn[x]=++sz; stk[++top]=x;
    for (int y = 0; y < n; y ++) if (G[x][y]) {
      if (!dfn[y]) {
        dfs(y,G); low[x]=min(low[x],low[y]);
      }
      else if (col[y]==-1) low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x]) {
      scc_cnt ++;
      do {
        col[stk[top]]=scc_cnt-1;
      } while (stk[top--]!= x);
    }
  }
  int solve(int n, const bool G[][MAXN]) {
    sz=top=scc_cnt=0; memset(dfn,0,sizeof(dfn));
    memset(col,-1,sizeof(col));
    for (int i=0;i<n;++i) if (!dfn[i]) dfs(i,G);
    return scc_cnt;
  }
} AC;

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++ i) {
      for (int j = 0; j < n; ++ j) {
        G[i][j] = 1;
      }
    }
    for (int i = 0; i < m; ++ i) {
      int x, y; scanf("%d%d", &x, &y);
      G[x - 1][y - 1] = 0;
    }
    int d; scanf("%d", &d);
    printf("%d\n", d * AC.solve(n, G));
  }
  return 0;
}

