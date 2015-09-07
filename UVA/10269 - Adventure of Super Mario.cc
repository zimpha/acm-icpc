#include <queue>
#include <cstdio>
#include <cstring>

const int MAXN=105;
const int MAXK=15;
const int inf=100000000;

struct node
{
    int u,t;
};

int g[MAXN][MAXN],dis[MAXN][MAXK];
bool vis[MAXN][MAXK];
int a,b,m,l,n;

int spfa()
{
    std::queue<node>q;
    while (!q.empty()) q.pop();
    for (int i=1; i<=a+b; i++)
	for (int j=0; j<=n; j++)
	{
	    dis[i][j]=inf;
	    vis[i][j]=0;
	}
    node now; now.u=a+b; now.t=0;
    q.push(now); dis[a+b][0]=0;
    while (!q.empty())
    {
	now=q.front(); q.pop();
	for (int v=1; v<=a+b; v++)
	{
	    if (g[now.u][v]+dis[now.u][now.t]<dis[v][now.t])
	    {
		dis[v][now.t]=g[now.u][v]+dis[now.u][now.t];
		if (!vis[v][now.t])
		{
		    node tmp;
		    vis[v][now.t]=1;
		    tmp.u=v; tmp.t=now.t;
		    q.push(tmp);
		}
	    }
	    if (g[now.u][v]<=l&&now.t<n&&dis[v][now.t+1]>dis[now.u][now.t])
	    {
		dis[v][now.t+1]=dis[now.u][now.t];
		if (!vis[v][now.t+1])
		{
		    node tmp;
		    tmp.u=v; tmp.t=now.t+1;
		    vis[v][now.t+1]=1;
		    q.push(tmp);
		}
	    }
	}
	vis[now.u][now.t]=0;
    }
    int ans=inf;
    for (int i=0; i<=n; i++)
	if (dis[1][n]<ans) ans=dis[1][n];
    return ans;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d%d%d%d%d",&a,&b,&m,&l,&n);
	for (int i=1; i<=a+b; i++)
	    for (int j=1; j<=a+b; j++)
		g[i][j]=(i==j)?0:inf;
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    if (g[u][v]>w) g[u][v]=g[v][u]=w;
	}
	for (int k=1; k<=a; k++)
	    for (int i=1; i<=a+b; i++)
		for (int j=1; j<=a+b; j++)
		    if (g[i][j]>g[i][k]+g[k][j]) g[i][j]=g[i][k]+g[k][j];
	int ans=spfa();
	printf("%d\n",ans);
    }
    return 0;
}
