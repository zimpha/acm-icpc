#include<cstdio>
#include<algorithm>
#define rep(i,l,n) for(int i=l;i<=n;i++)
#define dep(i,n,l) for(int i=n;i>=l;i--)
using namespace std;
const int N=210,inf=~0U>>2;
int T,n,m,i,j,k,flag,x[N],y[N],cnt,one,b[N],g[N],nxt[N],ans;
int size[N],f[N][N][10],t[N][10];
struct P{int l,r,w;P(){}P(int _l,int _r,int _w){l=_l,r=_r,w=_w;}}a[N];
inline bool cmp(int x,int y){return x>y;}
inline void up(int&a,int b){if(a<b)a=b;}
void dfs(int x){
  rep(a,0,m)rep(b,0,k)f[x][a][b]=-inf;f[x][0][0]=0;
  for(int i=g[x];i;i=nxt[i]){
    dfs(i);
    dep(a,min(size[x]+size[i],m),0)rep(b,0,k)t[a][b]=f[x][a][b];
    dep(a,min(size[x],m),0)dep(c,min(size[i],m-a),0){
      int t1=-inf,t2=-inf;
      rep(b,0,k){
        up(t1,f[i][c][b]);
        up(t2,f[x][a][b]);
        up(t[a+c][b],max(f[x][a][b]+t1,f[i][c][b]+t2));
      }
    }
    size[x]+=size[i];
    dep(a,min(size[x],m),0)rep(b,0,k)f[x][a][b]=t[a][b];
  }
  if(!x)return;
  size[x]++;
  dep(a,min(size[x],m-1),0)dep(b,k-1,0)up(f[x][a+1][b+1],f[x][a][b]+::a[x].w);
}
int main(){
  while(~scanf("%d%d%d",&n,&m,&k)){
    k--;
    rep(i,1,n)scanf("%d%d",&x[i],&y[i]);
    rep(i,1,n)rep(j,i+1,n)if(y[i]==y[j]){
      flag=1;
      rep(k,i+1,j-1)if(y[k]>=y[i]){flag=0;break;}
      if(flag){
        if(i+1==j){
          b[++one]=x[j]-x[i];
        }else{
          a[++cnt]=P(i+1,j-1,x[j]-x[i]);
        }
      }
    }
    if(one>1)sort(b+1,b+one+1,cmp);
    rep(i,2,one)b[i]+=b[i-1];
    rep(i,1,cnt){
      j=0;
      rep(k,1,cnt)if(a[k].l<a[i].l&&a[k].r>a[i].r)if(!j||a[k].w<a[j].w)j=k;
      nxt[i]=g[j],g[j]=i;
    }
    dfs(0);
    ans=-1;
    rep(i,m-one,m)rep(j,0,k)up(ans,f[0][i][j]+b[m-i]);
    printf("Case %d: %d\n",++T,ans);
    rep(i,0,cnt)g[i]=size[i]=0;
    cnt=one=0;
  }
  return 0;
}
