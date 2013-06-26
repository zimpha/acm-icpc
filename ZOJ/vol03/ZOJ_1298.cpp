#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

const int MAXN=505;
const int inf=100000000;

int g[MAXN][MAXN];
bool vis[MAXN];
int dis[MAXN];
double ans[3];
int n,m;

void Dijkstra()
{
    for (int i=1; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    dis[1]=0;
    while (1)
    {
	int tmp=inf,u;
	for (int i=1; i<=n; i++)
	    if (!vis[i]&&dis[i]<tmp)
	    {	
		tmp=dis[i];
		u=i;
	    }
	if (tmp==inf) break;
	vis[u]=1;
	for (int v=1; v<=n; v++)
	    if (!vis[v]&&dis[v]>dis[u]+g[u][v])
		dis[v]=dis[u]+g[u][v];
    }
    ans[0]=-1;
    for (int u=1; u<=n; u++)
	if (dis[u]>ans[0])
	{
	    ans[0]=dis[u];
	    ans[1]=u;
	}
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=n; j++)
		g[i][j]=(i==j)?0:inf;
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    g[u][v]=g[v][u]=w;
	}
	Dijkstra();
	bool flag=true;
	for (int i=1; i<=n; i++)
	    for (int j=i+1; j<=n; j++)
	    {
		int t1=min(dis[i],dis[j]);
		int t2=max(dis[i],dis[j]);
		if (g[i][j]!=inf&&t1+g[i][j]>t2)
		{
		    double tmp=(double)(g[i][j]+t1+t2)/2;
		    if (tmp>ans[0])
		    {
			flag=false;
			ans[0]=tmp;
			ans[1]=i;
			ans[2]=j;
		    }
		}
	    }
	printf("System #%d\n",++cas);
	if (flag) printf("The last domino falls after %.1f seconds, at key domino %.0f.\n\n",ans[0],ans[1]);
	else printf("The last domino falls after %.1f seconds, between key dominoes %.0f and %.0f.\n\n",ans[0],ans[1],ans[2]);
    }
    return 0;
}
