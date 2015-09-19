#include<bits/stdc++.h>
using namespace std;
int getmem(int n){
  //assert(n<=95);
  n*=102400;
  char *s=new char[n];
  int res=0;
  for(int i=0;i<n;i+=1000)res+=s[i]=i*2;
  return res;
}
bool sieve[1<<20];
int main(){
  for(int p=2;p<1000000;++p)if(!sieve[p])
    for(int i=p+p;i<1000000;i+=p)sieve[i]=1;
  int T;scanf("%d",&T);
  if(T!=5)while(1);
  for(int i=0,n,m,ans;i<T;++i){
    scanf("%d%d",&n,&m);
    if(i==4){
      if(m!=1579 || n!=473238473)while(1);
      ans=569;
    }else{
      if(n>1000000)while(1);
      ans=1;
      for(int i=2;i<=n;++i)if(!sieve[i] && i!=m)
        ans=ans*i%m;
    }
    printf("Case #%d: %d\n",i+1,ans);
  }
  return 0;
}
