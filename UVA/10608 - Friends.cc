#include <cstdio>
#include <cstring>

const int MAXN=30005;

int f[MAXN],sum[MAXN];
int n,m,ans;

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

void Union(int x,int y)
{
    x=find(x); y=find(y);
    if (x==y) return;
    f[x]=y; sum[y]+=sum[x];
    if (sum[y]>ans) ans=sum[y];
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) 
	{
	    f[i]=i; 
	    sum[i]=1;
	}
	ans=1;
	while (m--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    Union(u,v);
	}
	printf("%d\n",ans);
    }
    return 0;
}
