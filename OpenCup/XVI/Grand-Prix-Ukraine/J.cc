#include<bits/stdc++.h>
using namespace std;
typedef uint64_t u64;


int n,m;
int s[64];
int w[64];

void dfs(int k=0,int w=-1,int lcm=0){
  if(lcm>=64)return;
  if(k==m){
    ::w[lcm]+=w;
    return;
  }
  dfs(k+1,w,lcm);
  if(!lcm)lcm=1;
  dfs(k+1,-w,lcm/__gcd(lcm,s[k])*s[k]);
}
__int128 pm(__int128 x,int n){
  __int128 r=1;
  for(;n;n>>=1,x=x*x)
    if(n&1)r*=x;
  return r;
}
u64 floor_root(u64 y,int n){
  if(n==1)return y;
  if(1ULL<<n >y )return 1;
  u64 x=pow((long double)y,1/(long double)n);
  for(;pm(x,n)<=y;++x);
  return x-1;
}
u64 sol(){
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)scanf("%d",s+i);
  if(n==1)return 1;
  for(int i=0;i<m;++i)
    for(int j=0;j<m;++j)
      if(s[i]%s[j]==0)s[i]=s[j];
  sort(s,s+m);
  m=unique(s,s+m)-s;
  memset(w,0,sizeof(w));
  dfs();
  u64 l=0,r=1.005e17;
  for(;l+1<r;){
    u64 x=l+r>>1;
    __int128 res=1;
    for(int i=1;x>>i;++i)if(w[i]!=0)
      res+=w[i]*(__int128)(floor_root(x,i)-1);
    if(res >= n) r=x;
    else l=x;
  }
  return r;
}
int main(){
  int q;
  for(scanf("%d",&q);q--;)printf("%llu\n",sol());
}
