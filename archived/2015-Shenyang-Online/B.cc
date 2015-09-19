#include<bits/stdc++.h>
using namespace std;

int f[1<<18];
int main(){
  int T,tc=0,n,M;
  for(scanf("%d",&T);T--;){
    scanf("%d%d",&n,&M);
    f[0]=2%M;f[1]=10%M;
    int period=0;
    for(int i=2;!period;++i){
      f[i]=(f[i-1]*10+M-f[i-2])%M;
      if(f[i]==f[1] && f[i-1]==f[0])
        period=i-1;
    }
    int r=1;
    for(int t=2;n;n>>=1,t=t*t%period)
      if(n&1)r=r*t%period;
    printf("Case #%d: %d\n",++tc,(f[(r+1)%period]+M-1)%M);
  }
}
