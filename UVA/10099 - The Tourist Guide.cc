#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;
const int MAXM=10005;

struct node
{
    int u,v,w;
};

node e[MAXM];
int f[MAXN];
int n,m;

int find(int x)
{
    if (x!=f[x]) f[x]=find(f[x]);
    return f[x];
}

bool cmp(node a,node b)
{
    return (a.w>b.w);
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&n,&m)&&n)
    {
	for (int i=0; i<m; i++)
	    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	std::sort(e,e+m,cmp);
	int s,t,p,limit;
	scanf("%d%d%d",&s,&t,&p);
	for (int i=1; i<=n; i++) f[i]=i;
	for (int i=0; i<m; i++)
	    if (find(e[i].u)!=find(e[i].v))
	    {
		f[find(e[i].u)]=find(e[i].v);
		if (find(s)==find(t))
		{
		    limit=e[i].w;
		    break;
		}
	    }
	int ans=0;
	ans=p/(limit-1);
	if (p%(limit-1)) ans++;
	printf("Scenario #%d\n",++cas);
	printf("Minimum Number of Trips = %d\n\n",ans);
    }
    return 0;
}
