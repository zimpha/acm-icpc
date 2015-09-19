#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 10000 + 10, inf = 1e9;
int go[MAXN][2], val[MAXN][2], a[MAXN];
int st[MAXN], ed[MAXN];
int n, m, sz;

int newNode() {
  go[sz][0] = go[sz][1] = -1;
  val[sz][0] = val[sz][1] = inf;
  return sz ++;
}

namespace NF {
  const int MAXN=100000,MAXM=100000;
  struct Edge {
    int v,c,f,nx;//c:capcity, f:flow
    Edge() {}
    Edge(int v,int c,int f,int nx):v(v),c(c),f(f),nx(nx) {}
  } E[MAXM];
  int G[MAXN],cur[MAXN],pre[MAXN],dis[MAXN],gap[MAXN],N,sz;
  void init(int _n) {
    N=_n,sz=0; memset(G,-1,sizeof(G[0])*N);
  }
  void link(int u,int v,int c) {
    E[sz]=Edge(v,c,0,G[u]); G[u]=sz++;
    E[sz]=Edge(u,0,0,G[v]); G[v]=sz++;
  }
  bool bfs(int S,int T) {
    static int Q[MAXN]; memset(dis,-1,sizeof(dis[0])*N);
    dis[S]=0; Q[0]=S;
    for (int h=0,t=1,u,v,it;h<t;++h) {
      for (u=Q[h],it=G[u];~it;it=E[it].nx) {
        if (dis[v=E[it].v]==-1&&E[it].c>E[it].f) {
          dis[v]=dis[u]+1; Q[t++]=v;
        }
      }
    }
    return dis[T]!=-1;
  }
  int dfs(int u,int T,int low) {
    if (u==T) return low;
    int ret=0,tmp,v;
    for (int &it=cur[u];~it&&ret<low;it=E[it].nx) {
      if (dis[v=E[it].v]==dis[u]+1&&E[it].c>E[it].f) {
        if (tmp=dfs(v,T,min(low-ret,E[it].c-E[it].f))) {
          ret+=tmp; E[it].f+=tmp; E[it^1].f-=tmp;
        }
      }
    }
    if (!ret) dis[u]=-1; return ret;
  }
  int dinic(int S,int T) {
    int maxflow=0,tmp;
    while (bfs(S,T)) {
      memcpy(cur,G,sizeof(G[0])*N);
      while (tmp=dfs(S,T,inf)) maxflow+=tmp;
      if (maxflow >= inf) return -1;
    }
    return maxflow;
  }
}

void dfs(int u, int d) {
  if (u == -1) return;
  for (int o = 0; o < 2; ++ o) if (go[u][o] != -1) {
    if (d > 0) NF::link(u, go[u][o], val[u][o]);
    else NF::link(go[u][o], u, val[u][o]);
    dfs(go[u][o], d);
  }
}

int main() {
  int ncas; scanf("%d", &ncas);
  for (int cas = 1; cas <= ncas; ++ cas) {
    scanf("%d%d", &n, &m); sz = 0;
    int S = newNode(), T = newNode();
    for (int i = 0; i < n; ++ i) {
      int x; scanf("%d", &x);
      int &p = ed[i]; p = T;
      for (int j = 0; j < 8; ++ j) {
        int o = x >> j & 1;
        if (go[p][o] == -1) go[p][o] = newNode();
        p = go[p][o];
      }
      int &q = st[i]; q = S;
      for (int j = 7; j >= 0; -- j) {
        int o = x >> j & 1;
        if (go[q][o] == -1) go[q][o] = newNode();
        q = go[q][o];
      }
    }
    for (int i = 0, w, p; i < m; ++ i) {
      char op[100], s[100];
      scanf("%s%s%d", op, s, &w);
      int len = strlen(s);
      if (op[0] == 'S') p = T, reverse(s, s + len);
      else p = S;
      for (int j = 0; s[j]; ++ j) {
        int o = s[j] - '0';
        if (p == -1) break;
        if (!s[j + 1]) val[p][o] = min(val[p][o], w);
        p = go[p][o];
      }
    }
    NF::init(sz);
    for (int i = 0; i < n; ++ i) {
      NF::link(st[i], ed[i], inf);
    }
    dfs(S, 1); dfs(T, -1);
    printf("Case #%d: %d\n", cas, NF::dinic(S, T));
  }
  return 0;
}