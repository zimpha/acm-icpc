#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 300 + 10, MAXM = 300000, inf = 1e9;

int mark[MAXN][MAXN];
int val[MAXN][MAXN];
int cnt[MAXN];

namespace ZKW {
  struct Edge {
    int u,v,f,c,n;
    Edge() {}
    Edge(int u,int v,int f,int c,int n):u(u),v(v),f(f),c(c),n(n) {}
  } E[MAXM];
  bool negcircle;
  int G[MAXN],dis[MAXN],pre[MAXN],vis[MAXN];
  int S,T,sz,N,MinCost,MaxFlow; //S源点, T汇点
  void init(int n,int s,int t) {
    memset(G,-1,sizeof(G));
    sz=0; N=n; S=s; T=t;
  }
  void link(int u,int v,int f,int c) {//u -> v
    //cout << "add: " << u << " " << v << endl;
    E[sz]=Edge(u,v,f,+c,G[u]); G[u]=sz++;
    E[sz]=Edge(v,u,0,-c,G[v]); G[v]=sz++;
  }
  bool extand() {
    queue<int> Q;
    static int enq[MAXN]; negcircle = false;
    for (int i=0;i<=N;++i) enq[i]=0,dis[i]=inf,vis[i]=0,pre[i]=-1;
    Q.push(S); vis[S]=1; dis[S]=0;
    while (!Q.empty()) {
      int u=Q.front(),v; Q.pop(); vis[u]=0;
      enq[u] ++; if (enq[u] > N) {negcircle = true; break;}
      for (int h=G[u];~h;h=E[h].n) {
        if (E[h].f>0&&dis[v=E[h].v]>dis[u]+E[h].c) {
          dis[v]=dis[u]+E[h].c; pre[v]=h;
          if (!vis[v]) Q.push(v),vis[v]=1;
        }
      }
    }
    return !negcircle && dis[T]<inf; // 改成dis[T] <= 0 求可行流
  }
  int solve() {
    MinCost=MaxFlow=0;
    while (extand()) {
      int aug=inf;
      for (int h=pre[T];~h;h=pre[E[h].u]) aug=min(aug,E[h].f);
      MinCost+=aug*dis[T]; MaxFlow+=aug;
      for (int h=pre[T];~h;h=pre[E[h].u]) {
        E[h].f-=aug,E[h^1].f+=aug;
      }
    }
    return MinCost;
  }
  void ss(int n) {
    for (int u = 1; u <= n * 2; ++ u) {
      for (int it = G[u]; ~it; it = E[it].n) {
        int v = E[it].v, w = E[it].c;
        if (E[it].f > 1e6 && E[it ^ 1].f) {
          //cout << u << " " << v << " " << w << endl;
          val[v][u] = w, val[u][v] = -w;
        }
      }
    }
  }
}

int ret[MAXN], vis[MAXN];

void spfa(int n) {
  for (int i = 0; i < MAXN; ++ i) ret[i] = inf, vis[i] = 0;
  queue<int> Q; Q.push(0);
  ret[0] = 0; vis[0] = true;
  while (!Q.empty()) {
    int u = Q.front(); Q.pop(); vis[u] = 0;
    for (int v = 0; v <= n * 2; ++ v) {
      if (ret[v] > ret[u] + val[u][v]) {
        ret[v] = ret[u] + val[u][v];
        if (!vis[v]) Q.push(v), vis[v] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++ i) printf("%d ", ret[i]); puts("");
  for (int i = 1; i <= n; ++ i) printf("%d ", ret[i + n]); puts("");
}

int main() {
  int ncas; scanf("%d", &ncas);
  for (int cas = 1; cas <= ncas; ++ cas) {
    int N, M; scanf("%d%d", &N, &M);
    for (int i = 0; i <= N * 2; ++ i) cnt[i] = 0;
    int S = N + N + 2, T = S + 1, sum = 0;
    ZKW::init(N + N + 10, S, T);
    for (int i = 0; i <= S; ++ i) {
      for (int j = 0; j <= S; ++ j) {
        val[i][j] = inf;
      }
    }
    for (int _ = 0; _ < M; ++ _) {
      int i, j, v, l, r; scanf("%d%d%d%d%d", &i, &j, &v, &l, &r);
      sum += v; l -= v; r -= v; cnt[i] ++; cnt[j + N] ++;
      val[j + N][i] = r; val[i][j + N] = -l;
      ZKW::link(i, j + N, inf, +r);
      ZKW::link(j + N, i, inf, -l);
    }
    for (int i = 1; i <= N; ++ i) {
      val[i][0] = 0; val[0][i] = 1e6;
      val[i + N][0] = 0; val[0][i + N] = 1e6;
      ZKW::link(S, i, cnt[i], 0);
      ZKW::link(i + N, T, cnt[i + N], 0);
    }
    sum += ZKW::solve();
    if (ZKW::negcircle) puts("Unlike");
    else {
      printf("%d\n", sum);
      ZKW::ss(N);
      spfa(N);
    }
  }
  return 0;
}