#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

const int MAXN=105;
const int inf=100000000;

int cap[MAXN][MAXN],cost[MAXN][MAXN];
int dis[MAXN],pre[MAXN];
bool vis[MAXN];
int n,m,S,T;

bool spfa()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<=T; i++)
    {
	dis[i]=inf;
	vis[i]=0;
	pre[i]=-1;
    }
    q.push(S); dis[S]=0; vis[S]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	vis[u]=0;
	for (int v=0; v<=T; v++)
	    if (cap[u][v]>0&&dis[v]>dis[u]+cost[u][v])
	    {
		dis[v]=dis[u]+cost[u][v];
		pre[v]=u;
		if (!vis[v])
		{
		    vis[v]=1;
		    q.push(v);
		}
	    }
    }
    return (dis[T]<inf);
}

void mincost()
{
    int maxflow=0,sum=0;
    while (spfa())
    {
	int nec=inf;
	for (int u=T; pre[u]!=-1; u=pre[u])
	    nec=std::min(nec,cap[pre[u]][u]);
	sum+=nec*dis[T]; maxflow+=nec;
	for (int u=T; pre[u]!=-1; u=pre[u])
	{
	    cap[pre[u]][u]-=nec;
	    cap[u][pre[u]]+=nec;
	    cost[u][pre[u]]=-cost[pre[u]][u];
	}
    }
    if (maxflow==2) printf("%d\n",sum);
    else printf("Back to jail\n");
}

int main()
{
    while (scanf("%d",&n)&&n)
    {
	memset(cap,0,sizeof(cap));
	memset(cost,0,sizeof(cost));
	scanf("%d",&m);
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    cap[u][v]=cap[v][u]=1;
	    cost[u][v]=cost[v][u]=w;
	}
	S=0; T=n+1;
	cap[S][1]=2; cap[n][T]=2;
	mincost();
    }
    return 0;
}
