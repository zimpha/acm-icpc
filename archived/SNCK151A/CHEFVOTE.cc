#include <bits/stdc++.h>
using namespace std;
#define TR(i,v)       for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
#define DEBUG(x)      cout<<#x<<" = "<<x<<endl
#define SIZE(p)       (int)(p).size()
#define MP(a,b)       make_pair((a),(b))
#define ALL(p)        (p).begin(),(p).end()
#define rep(i,n)      for(int i=0;i<(int)(n);++i)
#define REP(i,a,n)    for(int i=(a);i<(int)(n); ++i)
#define FOR(i,a,b)    for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,b,a)   for(int i=(int)(b);i>=(int)(a);--i)
#define CLR(x,y)      memset((x),(y),sizeof((x)))
typedef long long LL;
typedef pair<int,int> pii;
namespace NF {
  typedef int VAL;
  typedef int MAXF_VAL;
  const int MAXN=55+55+10,MAXM=55*55*2;
  const VAL inf=1e9;
  struct Edge {
    int v;
    VAL c,f;
    int n;
    Edge() {}
    Edge(int v,VAL c,VAL f,int n):v(v),c(c),f(f),n(n){}
  }E[MAXM];
  int G[MAXN],cur[MAXN],pre[MAXN],dis[MAXN],gap[MAXN];
  int N,S,T,sz;
  void init(int _n,int _s,int _t){
    N=_n,S=_s,T=_t; sz=0;
    memset(G,-1,sizeof(G));
  }
  void addedge(int u,int v,VAL c){
    E[sz]=Edge(v,c,0,G[u]); G[u]=sz++;
    E[sz]=Edge(u,0,0,G[v]); G[v]=sz++;
  }
  MAXF_VAL ISAP(){
    MAXF_VAL maxflow=0;
    VAL aug=inf;
    int u,v;
    for (int i=0;i<=N;++i)cur[i]=G[i],gap[i]=dis[i]=0;
      for(gap[S]=N,u=pre[S]=S;dis[S]<N;){
        bool flag=false;
        for (int &h=cur[u];~h;h=E[h].n){
          if(E[h].c>E[h].f&&dis[u]==dis[v=E[h].v]+1){
            if(E[h].c-E[h].f<aug)aug=E[h].c-E[h].f;
            pre[v]=u,u=v; flag=true;
            if (u==T) {
              for (maxflow+=aug;u!=S;) {
                E[cur[u=pre[u]]].f+=aug;
                E[cur[u]^1].f-= aug;
              }
              aug=inf;
            }
            break;
          }
        }
        if (flag) continue;
        int mindis=N;
        for (int h=G[u];~h;h=E[h].n){
          if (E[h].c>E[h].f&&dis[E[h].v]<mindis){
            mindis=dis[E[h].v]; cur[u]=h;
          }
        }
        if ((--gap[dis[u]])==0) break;
        ++gap[dis[u]=mindis+1]; u=pre[u];
      }
      return maxflow;
    }
}
int main(){
  int T;scanf("%d",&T);
  while(T--){
    int n;scanf("%d",&n);
    int c[55];
    int sum=0;
    rep(i,n)scanf("%d",c+i),sum+=c[i];
    int o=1;
    rep(i,n)if(c[i]>=n ||c[i]<0)o=0;
    if(sum!=n)o=0;
    if(!o){
      puts("-1");
      continue;
    }
    int sr=2*n,sk=2*n+1;
    NF::init(n+n+2,sr,sk);
    rep(i,n){
      NF::addedge(sr,i,1);
      // printf("%d -> %d\n",i+n,sk);
      NF::addedge(i+n,sk,c[i]);
    }
    rep(i,n)
    rep(j,n)if(i!=j){
      // printf("%d -> %d\n",i,j+n);
      NF::addedge(i,j+n,1);
    }
    int f=NF::ISAP();    
    if(f!=n){
      puts("-1");
      continue;
    }
    rep(i,n){
      auto E=NF::E;
      auto G=NF::G;
      // DEBUG(i);
      for(int k=G[i];~k;k=E[k].n){
        NF::Edge e=E[k];
        // printf("%d %d %d\n",e.v-n,e.f,e.c);
        if(e.f==e.c){
          printf("%d%c",e.v-n+1," \n"[i+1==n]);
        }
        // break;
      }
    }
  }
  return 0;
}