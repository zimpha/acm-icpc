#include <cstdio>
#include <cstring>

const int MAXN=105;
const int inf=1000000000;

int g[MAXN][MAXN];
int level[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n, m;

int Dijkstra(int lower, int upper)
{
	for (int i=0; i<=n; i++)
	{
		dis[i]=inf;
		vis[i]=0;
	}
	dis[0]=0;
	while (1)
	{
		int u,min=inf;
		for (int i=0; i<=n; i++)
			if (!vis[i]&&level[i]>=lower&&level[i]<=upper&&dis[i]<min)
			{
				min=dis[i];
				u=i;
			}
		if (min==inf) break;
		vis[u]=1;
		for (int v=1; v<=n; v++)
			if (!vis[v]&&level[v]>=lower&&level[v]<=upper&&dis[v]>dis[u]+g[u][v])
				dis[v]=dis[u]+g[u][v];
	}
	return dis[1];
}

int main()
{
	while (scanf("%d%d",&m, &n)==2)
	{
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				g[i][j]=inf;
		for (int i=1; i<=n; i++)
		{
			int p, x, w;
			scanf("%d%d%d",&p, level+i, &x);
			g[0][i]=p;
			for (int j=0; j<x; j++)
			{
				scanf("%d%d",&p,&w);
				g[p][i]=w;
			}
		}
		int ans=inf;
		for (int i=1; i<=n; i++)
		{
			level[0]=level[i];
			int tmp=Dijkstra(level[i], level[i]+m);
			if (tmp<ans) ans=tmp;
		}
		printf("%d\n",ans);
	}
    return 0;
}
