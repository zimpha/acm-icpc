#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;
const int MAXM=20005;
const int inf=100000000;

struct node
{
    int u,v,cap,cost;
    int next;
};

struct edge
{
    int u,v,w;
};

node e[MAXM];
edge tmp[MAXM/4];
int head[MAXN];
int dis[MAXN],vis[MAXN],pre[MAXN];
int n,m,d,k;
int S,cnt;

void addedge(int u,int v,int cap,int cost)
{
    e[cnt].u=u; e[cnt].v=v; e[cnt].cap=cap; e[cnt].cost=cost; e[cnt].next=head[u]; head[u]=cnt++;
    e[cnt].u=v; e[cnt].v=u; e[cnt].cap=0; e[cnt].cost=-cost; e[cnt].next=head[v]; head[v]=cnt++;
}

bool spfa()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
	pre[i]=-1;
    }
    dis[S]=0; vis[S]=1; q.push(S);
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (int now=head[u]; now!=-1; now=e[now].next)
	{
	    int v=e[now].v;
	    if (e[now].cap>0&&dis[v]>dis[u]+e[now].cost)
	    {
		dis[v]=dis[u]+e[now].cost;
		pre[v]=now;
		if (!vis[v])
		{
		    vis[v]=1;
		    q.push(v);
		}
	    }
	}
	vis[u]=0;
    }
    return (dis[n]<inf);
}

void mincost()
{
    long long sum=0;
    int maxflow=0;
    while (spfa())
    {
	int nec=inf;
	for (int now=pre[n]; now!=-1; now=pre[e[now].u])
	    nec=std::min(nec,e[now].cap);
	sum+=(long long)nec*dis[n]; maxflow+=nec;
	for (int now=pre[n]; now!=-1; now=pre[e[now].u])
	{
	    e[now].cap-=nec;
	    e[now^1].cap+=nec;
	}
    }
    if (maxflow==d) printf("%lld\n",sum);
    else printf("Impossible.\n");
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
	for (int i=1; i<=m; i++)
	    scanf("%d%d%d",&tmp[i].u,&tmp[i].v,&tmp[i].w);
	scanf("%d%d",&d,&k);
	cnt=0; memset(head,-1,sizeof(head));
	addedge(S,1,d,0);
	for (int i=1; i<=m; i++)
	{
	    addedge(tmp[i].u,tmp[i].v,k,tmp[i].w);
	    addedge(tmp[i].v,tmp[i].u,k,tmp[i].w);
	}
	mincost();
    }
    return 0;
}
