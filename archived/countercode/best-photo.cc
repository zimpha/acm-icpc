#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
static const int MAXN = 1000000 + 10, MOD = 1e9 + 7;

struct Tarjan {
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

LL dp[MAXN], g[MAXN], pw[MAXN];
int leaf[MAXN], deg[MAXN];
vector<int> G[MAXN];

void dfs(int u, int cc) {
  dp[u] = 1; int c(0);
  for (auto &v: G[u]) if (AC.col[v] != cc) {
    dfs(v, cc);
    leaf[u] += leaf[v];
    dp[u] = dp[u] * dp[v] % MOD;
    ++ c;
  }
  g[u] = dp[u];
  if (c) dp[u] = dp[u] * c % MOD;
}

int a[MAXN];
void brute(int n) {
  static int p[MAXN];
  for (int i = 0; i < n; ++ i) p[i] = i;
  int mx(-1), cnt(0);
  do {
    int tmp(0);
    for (int i = 1; i < n; ++ i) {
      if (p[i - 1] == a[p[i]]) ++ tmp;
    }
    if (tmp > mx) mx = tmp, cnt = 1;
    else if (tmp == mx) cnt ++;
  } while (next_permutation(p, p + n));
  printf("%d %d\n", mx, cnt);
}

int main() {
  pw[0] = 1;
  for (int i = 1; i < MAXN; ++ i) pw[i] = pw[i - 1] * 2 % MOD;
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++ i) {
    int x; scanf("%d", &x);
    a[i] = x - 1;
    G[x - 1].push_back(i);
    deg[x - 1] ++;
  }
  //brute(n);
  for (int i = 0; i < n; ++ i) leaf[i] = deg[i] == 0;
  AC.solve(n, G);
  LL ret = 1, lc(0);
  for (int i = 0; i < AC.scc_cnt; ++ i) {
    if (AC.SCC[i].size() == 1) continue;
    int cnt(0);
    LL sub(1), f0(1), f1(0);
    for (auto &u: AC.SCC[i]) {
      dfs(u, i);
      sub = sub * g[u] % MOD;
      lc += leaf[u];
      if (leaf[u]) {
        LL t0 = (f0 + f1) * g[u];
        LL t1 = (f0 + f1) * dp[u];
        ++ cnt;
        f0 = t0 % MOD, f1 = t1 % MOD;
      }
    }
    if (cnt == 0) lc ++, ret = ret * AC.SCC[i].size() % MOD;
    else ret = ret * (f0 + f1 - sub) % MOD;
    ret %= MOD; ret = (ret + MOD) % MOD;
  }
  for (int i = 1; i <= lc; ++ i) {
    ret = ret * i % MOD;
  }
  printf("%d %lld\n", n - (int)lc, ret);
  return 0;
}