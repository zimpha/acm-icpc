#include<cstdio>
#include<cmath>
#include<algorithm>
const int N=200010,M=10010;
int T,n,m,d,i,x,y,id[N],root,cmp_d,X1,X2,Y1,Y2,lim,l,r,k;
struct P{int x,y;}a[N];
struct Q{int l,r,id;}q[M];long long now,ans[M];
inline bool cmpq(const Q&a,const Q&b){return a.l/lim<b.l/lim||a.l/lim==b.l/lim&&a.r<b.r;}
struct node{int d[2],l,r,Max[2],Min[2],val,sum,f;}t[N];
inline bool cmp(const node&a,const node&b){return a.d[cmp_d]<b.d[cmp_d];}
inline void umax(int&a,int b){if(a<b)a=b;}
inline void umin(int&a,int b){if(a>b)a=b;}
inline void up(int x){
  if(t[x].l){
    umax(t[x].Max[0],t[t[x].l].Max[0]);
    umin(t[x].Min[0],t[t[x].l].Min[0]);
    umax(t[x].Max[1],t[t[x].l].Max[1]);
    umin(t[x].Min[1],t[t[x].l].Min[1]);
  }
  if(t[x].r){
    umax(t[x].Max[0],t[t[x].r].Max[0]);
    umin(t[x].Min[0],t[t[x].r].Min[0]);
    umax(t[x].Max[1],t[t[x].r].Max[1]);
    umin(t[x].Min[1],t[t[x].r].Min[1]);
  }
}
int build(int l,int r,int D,int f){
  int mid=(l+r)>>1;
  cmp_d=D,std::nth_element(t+l+1,t+mid+1,t+r+1,cmp);
  id[t[mid].f]=mid;
  t[mid].f=f;
  t[mid].Max[0]=t[mid].Min[0]=t[mid].d[0];
  t[mid].Max[1]=t[mid].Min[1]=t[mid].d[1];
  t[mid].val=t[mid].sum=0;
  if(l!=mid)t[mid].l=build(l,mid-1,!D,mid);else t[mid].l=0;
  if(r!=mid)t[mid].r=build(mid+1,r,!D,mid);else t[mid].r=0;
  return up(mid),mid;
}
inline void change(int x,int p){for(t[x].val+=p;x;x=t[x].f)t[x].sum+=p;}
void ask(int x){
  if(t[x].Min[0]>X2||t[x].Max[0]<X1||t[x].Min[1]>Y2||t[x].Max[1]<Y1||!t[x].sum)return;
  if(t[x].Min[0]>=X1&&t[x].Max[0]<=X2&&t[x].Min[1]>=Y1&&t[x].Max[1]<=Y2){k+=t[x].sum;return;}
  if(t[x].d[0]>=X1&&t[x].d[0]<=X2&&t[x].d[1]>=Y1&&t[x].d[1]<=Y2)k+=t[x].val;
  if(t[x].l)ask(t[x].l);
  if(t[x].r)ask(t[x].r);
}
inline void add(int x){
  X1=a[x].x-d,X2=a[x].x+d,Y1=a[x].y-d,Y2=a[x].y+d;
  k=0,ask(root),now+=k;
  change(id[x],1);
}
inline void del(int x){
  change(id[x],-1);
  X1=a[x].x-d,X2=a[x].x+d,Y1=a[x].y-d,Y2=a[x].y+d;
  k=0,ask(root),now-=k;
}
int main(){
  while(~scanf("%d%d%d",&n,&d,&m)){
    printf("Case %d:\n",++T);
    lim=(int)std::sqrt(n+0.5);
    for(i=1;i<=n;i++){
      scanf("%d%d",&x,&y);
      t[i].d[0]=a[i].x=x+y,t[i].d[1]=a[i].y=x-y,t[i].f=i;
    }
    root=build(1,n,0,0);
    for(i=1;i<=m;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    std::sort(q+1,q+m+1,cmpq);
    for(i=l=1,r=now=0;i<=m;i++){
      int L=q[i].l,R=q[i].r;
      if(r<R){for(r++;r<=R;r++)add(r);r--;}
      if(r>R)for(;r>R;r--)del(r);
      if(l<L)for(;l<L;l++)del(l);
      else if(l>L){for(l--;l>=L;l--)add(l);l++;}
      ans[q[i].id]=now;
    }
    for(i=1;i<=m;i++)printf("%lld\n",ans[i]);
  }
  return 0;
}