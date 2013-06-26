#include <cstdio>
#include <cstring>

const int MAXN=1005;
const int inf=10000000;

double x[MAXN],y[MAXN];
bool g[MAXN][MAXN];
bool vis[MAXN];
int dis[MAXN];
int n,m,S,T;

double dist(int i,int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void Dijkstra()
{
    for (int i=1; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    dis[S]=0;
    while (1)
    {
	int min=inf,u;
	for (int i=1; i<=n; i++)
	    if (!vis[i]&&dis[i]<min)
	    {
		min=dis[i];
		u=i;
	    }
	if (min==inf) break;
	vis[u]=1;
	for (int v=1; v<=n; v++)
	    if (!vis[v]&&g[u][v]&&dis[v]>dis[u]+1)
		dis[v]=dis[u]+1;
    }
}

int main()
{
	int cas;
	scanf("%d", &cas);
	while (cas--)
	{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	double limit,l1,l2;
	scanf("%d%d%d%lf%lf",&n,&S,&T,&l1,&l2);
	limit=l1+l2;
	memset(g,0,sizeof(g));
	for (int i=1; i<=n; i++)
	{
	    scanf("%lf%lf",x+i,y+i);
	    for (int j=1; j<i; j++)
		if (dist(i,j)<=limit*limit) 
		    g[i][j]=g[j][i]=1;
	}
	Dijkstra();
	if (dis[T]==inf) printf("Impossible\n");
	else printf("%d\n",dis[T]);
    }
    if (cas) puts("");
    }
    return 0;
}
