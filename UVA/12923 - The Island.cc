#include <bits/stdc++.h>
using namespace std;

namespace ZKW {
  const int MAXN = 50000 + 10, MAXM = 300000, inf = 1e9;
  struct Edge {
    int v,f,c,nx;
    Edge() {}
    Edge(int v,int f,int c,int nx):v(v),f(f),c(c),nx(nx) {}
  } E[MAXM];
  int G[MAXN],dis[MAXN],Q[MAXN];
  bool vis[MAXN],mark[MAXN];
  int N,S,T,sz,mincost;
  void init(int _n, int _s, int _t) {
    N = _n; S = _s; T = _t; sz = 0;
    memset(G, -1, sizeof(G[0]) * N);
  }
  void link(int u, int v, int f, int c) {
    E[sz]=Edge(v,f,+c,G[u]); G[u]=sz++;
    E[sz]=Edge(u,0,-c,G[v]); G[v]=sz++;
  }
  bool spfa() {
    for (int i=0;i<N;++i) dis[i]=inf,vis[i]=0;
    dis[T]=0; Q[0]=T; vis[T]=1;
    for (int h=0,t=1;h!=t; ) {
      int u=Q[h++],v; vis[u]=false;
      if (h==MAXN) h=0;
      for (int it=G[u];~it;it=E[it].nx) {
        if (dis[u]-E[it].c<dis[v=E[it].v]&&E[it^1].f) {
          dis[v]=dis[u]-E[it].c;
          if (!vis[v]) {
            vis[v]=true; Q[t++]=v;
            if (t==MAXN) t=0;
          }
        }
      }
    }
    return dis[S]!=inf;
  }
  int dfs(int u, int low) {
    mark[u]=true; if (u==T) return low;
    int ret=0,tmp=0;
    for (int it=G[u],v;~it&&ret<low;it=E[it].nx) {
      if (E[it].f&&!mark[v=E[it].v]&&dis[u]-E[it].c==dis[v]) {
        tmp=dfs(v,min(E[it].f,low-ret));
        E[it].f-=tmp; E[it^1].f+=tmp;
        mincost+=E[it].c*tmp; ret+=tmp;
      }
    }
    return ret;
  }
  int solve() {
    int maxflow = 0; mincost = 0;
    while (spfa()) {
      mark[T] = true;
      while (mark[T]) {
        memset(mark, 0, sizeof(mark[0]) * N);
        maxflow += dfs(S, inf);
      }
    }
    return mincost;
  }
}

int main() {
  int n; 
  while (scanf("%d", &n) == 1) {
    int S(0), T = n * 2 + 9;
    ZKW::init(n * 2 + 10, S, T);
    for (int i = 1; i <= n; ++ i) {
      ZKW::link(S, i, 1, 0);
      ZKW::link(i + n, T, 1, 0);
      for (int j = 1; j <= n; ++ j) {
        int x; scanf("%d", &x);
        ZKW::link(i, j + n, 1, -x);
      }
    }
    int ret = ZKW::solve();
    printf("%d\n", -ret);
  }
  return 0;
}