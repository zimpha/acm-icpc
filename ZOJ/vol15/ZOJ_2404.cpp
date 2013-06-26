#include <cstring>
#include <cstdio>
#define MAXN 210
#define inf 1000000

struct point
{
    int x,y;
};

point m[MAXN],h[MAXN];
int cost[MAXN][MAXN],cap[MAXN][MAXN];
int dis[MAXN],pre[MAXN],que[MAXN*10];
bool vis[MAXN];
int n,r,n1,n2;

int abs(int a)
{
    return (a>0)?a:-a;
}

int min(int a,int b)
{
    return (a<b)?a:b;
}

bool spfa()
{
    for (int i=0; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
	pre[i]=-1;
    }
    dis[0]=0; vis[0]=1; que[0]=0;
    int head=0,tail=0;
    while (head<=tail)
    {
	int u=que[head++];
	for (int v=0; v<=n; v++)
	    if (cap[u][v]>0&&dis[v]>dis[u]+cost[u][v])
	    {
		pre[v]=u;
		dis[v]=dis[u]+cost[u][v];
		if (!vis[v])
		{
		    que[++tail]=v;
		    vis[v]=1;
		}
	    }
	vis[u]=0;
    }
    if (dis[n]==inf) return false;
    else return true;
}

void mincost()
{
    int cost=0;
    while (spfa())
    {
	int nec=inf;
	for (int u=n; pre[u]!=-1; u=pre[u])
	{
	    nec=min(nec,cap[pre[u]][u]);
	}
	cost+=nec*dis[n];
	for (int u=n; pre[u]!=-1; u=pre[u])
	{
	    cap[pre[u]][u]-=nec;
	    cap[u][pre[u]]+=nec;
	}
    }
    printf("%d\n",cost);
}

int main()
{
    while (scanf("%d%d",&n,&r)==2&&n)
    {
	n1=n2=0;
	for (int i=0; i<n; i++)
	{
	    char c;
	    getchar();
	    for (int j=0; j<r; j++)
	    {
		c=getchar();
		if (c=='H') n1++,h[n1].x=i,h[n1].y=j;
		if (c=='m') n2++,m[n2].x=i,m[n2].y=j; 
	    }
	}

	n=n1+n2+1;
	memset(cap,0,sizeof(cap));
	memset(cost,0,sizeof(cost));
	for (int i=1; i<=n1; i++)
	    cap[0][i]=1,cost[0][i]=0;
	for (int i=1; i<=n1; i++)
	    cap[i+n1][n]=1,cost[i+n1][n]=0;
	for (int i=1; i<=n1; i++)
	    for (int j=1; j<=n2; j++)
	    {
		cap[i][j+n1]=1;
		cost[i][j+n1]=abs(h[i].x-m[j].x)+abs(h[i].y-m[j].y);
		cost[j+n1][i]=-cost[i][j+n1];
	    }
	
	mincost();
    }
    return 0;
}
