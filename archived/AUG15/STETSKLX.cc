/*
¶þ·Ö´ð°¸x£¬°Ñ>=xµÄÖÃ1£¬<xµÄÖÃ-1
Ê÷·ÖÖÎÕÒÂú×ãÌõ¼þµÄÈ¨ÖµºÍ×î´óµÄÁ´£¬Èô×î´óÖµ>=0Ôò¿ÉÐÐ
Ã¿´ÎÏàµ±ÓÚÑ¯ÎÊÒ»¸ö¶¨³¤Çø¼ä£¬ÇÒÇø¼äµ¥µ÷ÒÆ¶¯£¬ËùÒÔÓÃµ¥µ÷¶ÓÁÐÎ¬»¤
ÓÅ»¯
1.ÏÈÊ÷·ÖÖÎÔÙ¶þ·Ö´ð°¸£¬¿ÉÒÔ²»¶ÏÌá¸ßÏÂ½ç
2.ÈôÄ³×ÓÊ÷size<L,Ôò¿ÉÒÔÎÞÊÓ
*/
#include<cstdio>
#include<algorithm>
#define N 100010
using namespace std;
inline void read(int&a){char c;while(!((c=getchar())>='0')&&(c<='9'));a=c-'0';while(((c=getchar())>='0')&&(c<='9'))(a*=10)+=c-'0';}
int n,i,tot,g[N],nxt[N<<1],v[N<<1],w[N<<1],x,y,z,son[N],f[N],size,now,b[N],pos;bool ok[N<<1];
int ans,L,R,t[N],d[N],dep[N],sum[N],vis[N];
int head,tail,q[N];
int Q[N],H,T,P;//µ¥µ÷µÝ¼õ¶ÓÁÐ
bool flag;
inline void add(int x,int y,int z){v[tot]=y,w[tot]=z,nxt[tot]=g[x],ok[tot]=1,g[x]=tot++;}
void findroot(int x,int pre){
  son[x]=1;f[x]=0;
  for(int i=g[x];~i;i=nxt[i])if(ok[i]&&v[i]!=pre){
    findroot(v[i],x);
    son[x]+=son[v[i]];
    if(son[v[i]]>f[x])f[x]=son[v[i]];
  }
  if(size-son[x]>f[x])f[x]=size-son[x];
  if(f[x]<f[now])now=x;
}
void solve(int x){
  int l=1,r=ans-1,mid;
  while(l<=r){
    mid=(l+r)>>1;flag=0;
    vis[x]=t[0]=++pos,d[0]=0;//d[i]µ½¸ù¾àÀëÎªiµÄ×î´óÖµ
    for(int I=g[x];~I;I=nxt[I])if(ok[I]){//±éÀúxµÄÃ¿¿Ã×ÓÊ÷
      q[head=tail=0]=v[I];
      dep[v[I]]=1;sum[v[I]]=w[I]<=b[mid]?1:-1;vis[v[I]]=pos;
      while(head<=tail){//¶Ô¸Ã×ÓÊ÷ÇóBFSÐò²¢¼ÆËãµ½x×ß¹ýµÄ±ßÊýÒÔ¼°ºÍ
        int y=q[head++],i;
        for(i=g[y];~i;i=nxt[i])if(ok[i]&&vis[v[i]]!=pos)vis[v[i]]=pos,q[++tail]=v[i],dep[v[i]]=dep[y]+1,sum[v[i]]=sum[y]+(w[i]<=b[mid]?1:-1);
      }
      H=1;T=0;P=R-1;
      for(int i=0;i<=tail;i++){//max(d[j]),L-dep[q[i]]<=j<=R-dep[q[i]]
        if(dep[q[i]]>R)break;
        while(~P&&P>=L-dep[q[i]]){
          if(t[P]==pos){
            while(H<=T&&d[Q[T]]<=d[P])T--;
            Q[++T]=P;
          }
          P--;
        }
        while(H<=T&&Q[H]>R-dep[q[i]])H++;
        if(H<=T&&d[Q[H]]+sum[q[i]]>0){flag=1;break;}
      }
      for(int i=0;i<=tail;i++)if(t[dep[q[i]]]!=pos)t[dep[q[i]]]=pos,d[dep[q[i]]]=sum[q[i]];else if(d[dep[q[i]]]<sum[q[i]])d[dep[q[i]]]=sum[q[i]];
    }
    if(flag)r=(ans=mid)-1;else l=mid+1;
  }
  for(int i=g[x];~i;i=nxt[i])if(ok[i]){
    ok[i^1]=0;
    if(son[v[i]]<L)continue;
    f[0]=size=son[v[i]];findroot(v[i],now=0);solve(now);
  }
}
int main(){
  int T; read(T);
  for (int _ = 0; _ < T; ++ _) {
    read(n);read(L);read(R); tot = 0;
    for(i=1;i<=n;i++)g[i]=-1;
    for(i=1;i<n;i++)read(x),read(y),read(z),add(x,y,z),add(y,x,z),b[i]=z;
    ans=n-1;
    sort(b+1,b+n);b[ans=n]=-1;
    f[0]=size=n;findroot(1,now=0);
    solve(now);
    printf("%d\n",b[ans]);
  }
  return 0;
}