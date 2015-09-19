#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int c[]={6,2,5,5,4,5,6,3,7,6};
ll m,ta;
inline void to(int&x){x=(x+ta)%m;}


int mem[2][6000], *f=mem[0],*g=mem[1];
int sol(){
  int n;
  scanf("%d%lld",&n,&m);
  n-=3;
  f[0]=1;
  ll res=0;
  int w=0;
  int tm=0;
  for(bool ok=true;ok;){
    memset(g,0,sizeof(mem[0]));
    ++tm;
    ok=false;
    for(int st=0;st<=w;++st)
      if(ta=f[st]){
        int used=st>>3,
            ae=st>>2&1,be=st>>1&1, up=st&1;
        if(ae && be){
          if(used+(up?c[1]:0) == n)
            res+=ta;
          continue;
        }
        if(ae){
          for(int i=0;i<10;++i){
            int us=used+c[i]+c[(i+up)%10],pp=(i+up)/10;
            if(us+(pp<<1)> n) continue;
            to(g[us<<3|4|pp]);
            if(i)to(g[us<<3|6|pp]);
            ok=true;
            w=max(w,us<<3|6|pp);
          }
          continue;
        }
        for(int a=0;a<10;++a)
          for(int b=0;b<10;++b){
            const int us=used+c[a]+c[b]+c[(a+b+up)%10],pp=(a+b+up)/10;
            if(us+(pp<<1)>n)continue;
            const int tmp=us<<3|pp;
            to(g[tmp]);
            if(a)to(g[tmp|4]);
            if(b)to(g[tmp|4]);
            if(a&&b)to(g[tmp|6]);
            ok=true;
            w=max(w,tmp|6);
          }
      }
    swap(f,g);
  }
  return res%m;
}

int main(){
  int T;
  scanf("%d",&T);
  for(int i=1;i<=T;++i)
    printf("Case #%d: %d\n",i,sol());
}
