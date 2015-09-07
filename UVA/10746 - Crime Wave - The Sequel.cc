#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

const int MAXN=50;
const int inf=1<<30;

bool vis[MAXN];
int cap[MAXN][MAXN],pre[MAXN];
double cost[MAXN][MAXN],dis[MAXN];
int n,m,S,T;

bool spfa()
{
	std::queue<int>q;
	while (!q.empty()) q.pop();
	for (int i=0; i<=T; i++)
    {
    	dis[i]=inf; vis[i]=0;
    	pre[i]=-1;
    }
    dis[S]=0; vis[S]=1; q.push(S);
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int v=0; v<=T; v++)
        {
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
        vis[u]=0;
    }
    if (dis[T]==inf) return false;
    else return true;
}

double mincost()
{
    double sum=0.0;
    while(spfa())
    {
        int nec=inf;
        for (int u=T; u!=S; u=pre[u])
            nec=std::min(nec,cap[pre[u]][u]);
        for (int u=T; u!=S; u=pre[u])
        {
            cap[pre[u]][u]-=nec;
            cap[u][pre[u]]+=nec;
        }
        sum+=dis[T]*nec;
    }
    return sum;
}
int main()
{
    while (scanf("%d%d",&n,&m)==2&&n&&m)
    {
        S=0; T=m+n+1;
        memset(cost,0,sizeof(cost));
        memset(cap,0,sizeof(cap));
        for (int i=1; i<=n; i++) cap[0][i]=1;
        for (int i=1; i<=m; i++) cap[i+n][T]=1;
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
            {
                scanf("%lf",&cost[i][j+n]);
                cost[j+n][i]=-cost[i][j+n];
                cap[i][j+n]=1;
            }
        double ans=mincost();
        printf("%.2lf\n",(ans+1E-6)/n);
    }
    return 0;
}
