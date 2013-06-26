#include <stdio.h>
#define MAXN 5510
#define inf 1000000000

int tree[MAXN*2];
int a[MAXN];
int n,ans;

int min(int a,int b)
{
    if (a<b) return a;
    else return b;
}

void modify(int ll,int l,int r,int n)
{
    int mid;
    tree[n]++;
    if (l==r) return;
    mid=(l+r)/2;
    if (ll<=mid) modify(ll,l,mid,n*2);
    else modify(ll,mid+1,r,n*2+1);
}

int getsum(int ll,int rr,int l,int r,int n)
{
    int mid;
    if (ll>rr) return 0;
    if (ll==l&&rr==r) return tree[n];
    mid=(l+r)/2;
    if (rr<=mid) return getsum(ll,rr,l,mid,n*2);
    else
       if (ll>mid) return getsum(ll,rr,mid+1,r,n*2+1);
       else return (getsum(ll,mid,l,mid,n*2)+getsum(mid+1,rr,mid+1,r,n*2+1));
}

void solve()
{
    int i,sum=0;
    memset(tree,0,sizeof(tree));
    for (i=n;i>=1;i--)
    {
        sum+=getsum(1,a[i]-1,1,n,1);
        modify(a[i],1,n,1);
    }
    ans=sum;
    for (i=1;i<n;i++)
    {
        sum+=n-a[i]-a[i]+1;
        ans=min(ans,sum);
    }
}

int main()
{
    int i;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]++;
        }
        solve();
        printf("%d\n",ans);
    }

    return 0;
}
