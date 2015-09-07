#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=755;
const int MAXM=300000;

struct node
{
    int u,v,w;
};

node e[MAXM];
int x[MAXN];
int y[MAXN];
int f[MAXN];
int n,m;

bool cmp(node a,node b)
{
    return (a.w<b.w);
}

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

void Union(int x,int y)
{
    x=find(x); y=find(y);
    f[x]=y;
}

int main()
{
    while (scanf("%d",&n)==1)
    {
	for (int i=1; i<=n; i++)
	    scanf("%d%d",x+i,y+i);
	for (int i=1; i<=n; i++) f[i]=i;
	scanf("%d",&m);
	while (m--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    Union(u,v);
	}
	m=0;
	for (int i=1; i<=n; i++)
	    for (int j=1; j<i; j++)
	    {
		e[m].u=i; e[m].v=j;
		e[m].w=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		m++;
	    }
	std::sort(e,e+m,cmp);
	double ans=0;
	for (int i=0; i<m; i++)
	    if (find(e[i].u)!=find(e[i].v))
	    {
		ans+=sqrt(e[i].w);
		Union(e[i].u,e[i].v);
	    }
	printf("%.2f\n",ans);
    }
    return 0;
}
