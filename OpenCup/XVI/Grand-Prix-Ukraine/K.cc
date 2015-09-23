#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[3001][5120],s[5120],sh;
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i){
    scanf("%d",s+i);
    sh+=s[i]*i;
    s[i]+=s[i-1];
  }
  for(int i=2;i<=m;++i){
    static ll b[5120];
    static int q[5120],h,t;
    for(int j=i-1;j<=n;++j)b[j]=f[i-1][j]+j*(ll)s[j];
    q[h=t=0]=i-1;
    for(int j=i;j<=n;++j){
      for(;h<t && b[q[h]]-b[q[h+1]]+(ll)s[j]*(q[h+1]-q[h])>=0;) ++h;
      f[i][j] = b[q[h]]-(ll)q[h]*s[j];
      for(;t>h;--t) {
        int u=q[t-1],v=q[t];
        if(b[v]*(j-u)-(b[j]-b[u])*v < j*b[u]-u*b[j])
          break;
      }
      q[++t]=j;
    }
  }
  printf("%d\n",f[m][n]+sh);
}
