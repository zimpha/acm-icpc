#include <bits/stdc++.h>
using namespace std;

const int SZ = 52;
struct Bignum {
  int a[52];
  Bignum() {
    memset(a, 0, sizeof(a));
  }
  Bignum(char c) {
    memset(a, 0, sizeof(a));
    if (c >= 'A' && c <= 'Z') a[51 - (c - 'A')] = 1;
    else a[25 - (c - 'a')] = 1;
  }
  bool operator < (const Bignum &rhs) const {
    for (int i = SZ - 1; i >= 0; -- i)  {
      if (a[i] < rhs.a[i]) return true;
      else if (a[i] > rhs.a[i]) return false;
    }
    return false;
  }
  bool operator > (const Bignum &rhs) const {
    for (int i = SZ - 1; i >= 0; -- i) {
      if (a[i] < rhs.a[i]) return false;
      else if (a[i] > rhs.a[i]) return true;
    }
    return false;
  }
  Bignum operator + (const Bignum &rhs) const  {
    Bignum ret;
    for (int i = 0; i < SZ; ++ i) ret.a[i] = a[i] + rhs.a[i];
      return ret;
  }
  Bignum operator - (const Bignum &rhs) const  {
    Bignum ret;
    for (int i = 0; i < SZ; ++ i) ret.a[i] = a[i] - rhs.a[i];
      return ret;
  }
} ZERO, INF;

namespace NF {
    const int MAXN=200,MAXM=100000,inf=1e9;
    struct Edge {
        int u,v,f,n;
        Bignum c;
        Edge() {}
        Edge(int u,int v,int f,Bignum c,int n):u(u),v(v),f(f),n(n) {
          this->c = c;
        }
    } E[MAXM];
    int G[MAXN];
    Bignum dis[MAXN];
    int pre[MAXN],vis[MAXN];
    int S,T,sz,N,MaxFlow; //S源点, T汇点
    Bignum MinCost;
    void init(int n,int s,int t) {
        memset(G,-1,sizeof(G));
        sz=0; N=n; S=s; T=t;
    }
    void link(int u,int v,int f,Bignum c) {//u -> v
        E[sz]=Edge(u,v,f,c,G[u]); G[u]=sz++;
        E[sz]=Edge(v,u,0,ZERO-c,G[v]); G[v]=sz++;
    }
    bool extand() {
        queue<int> Q;
        for (int i=0;i<=N;++i) dis[i]=INF,vis[i]=0,pre[i]=-1;
        Q.push(S); vis[S]=1; dis[S]=ZERO;
        while (!Q.empty()) {
            int u=Q.front(),v; Q.pop(); vis[u]=0;
            for (int h=G[u];~h;h=E[h].n) {
                if (E[h].f>0&&dis[v=E[h].v]>dis[u]+E[h].c) {
                    dis[v]=dis[u]+E[h].c; pre[v]=h;
                    if (!vis[v]) Q.push(v),vis[v]=1;
                }
            }
        }
        return dis[T]<INF;
    }
    void solve() {
        MinCost=ZERO;
        int MaxFlow=0;
        while (extand()) {
            int aug=inf;
            for (int h=pre[T];~h;h=pre[E[h].u]) aug=min(aug,E[h].f);
            if (aug) MinCost = MinCost + dis[T];
            MaxFlow+=aug;
            for (int h=pre[T];~h;h=pre[E[h].u]) E[h].f-=aug,E[h^1].f+=aug;
        }
    }
}

int n;
Bignum tt[52];
char s[100];

char gao(int i) {
  if (i >= 26) return char('A' + 51 - i);
  else return char('a' + 25 - i);
}

int main() {
  for (int i = 0; i < 52; ++ i) INF.a[i] = 100;
  for (int i = 0; i < 52; ++ i) tt[i].a[51 - i] = 1;
  scanf("%d", &n);
  NF::init(n * 2 + 10, n * 2, n * 2 + 1);
  for (int i = 0; i < n; ++ i) {
    NF::link(NF::S, i, 1, ZERO);
    NF::link(i + n, NF::T, 1, ZERO);
  }
  for (int i = 0; i < n; ++ i) {
    scanf("%s", s);
    for (int j = 0; j < n; ++ j) {
      NF::link(i, j + n, 1, ZERO - Bignum(s[j]));
    }
  }
  NF::solve();
  Bignum ret = ZERO - NF::MinCost;
  char ans[60]; int sz = 0;
  for (int i = 51; i >= 0; -- i) {
    while (ret.a[i] --) {
      ans[sz ++] = gao(i);
    }
  }
  ans[sz] = 0;
  puts(ans);
  return 0;
}
