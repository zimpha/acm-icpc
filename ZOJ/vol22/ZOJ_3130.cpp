#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=70;
const int MAXM=20005;
const int inf=100000000;

struct node
{
    int u,v,cap,cost;
    int next;
};

node e[MAXM];
int head[MAXN];
int dis[MAXN],vis[MAXN];
int pre[MAXN];
int n,m,cnt;
int S,T;

void addedge(int u,int v,int cap,int cost)
{
    e[cnt].u=u; e[cnt].v=v; e[cnt].cap=cap; e[cnt].cost=cost;
    e[cnt].next=head[u]; head[u]=cnt++;
    e[cnt].u=v; e[cnt].v=u; e[cnt].cap=0; e[cnt].cost=-cost; 
    e[cnt].next=head[v]; head[v]=cnt++;
}

bool spfa()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<=T; i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    memset(pre,-1,sizeof(pre));
    q.push(S); dis[S]=0; vis[S]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (int now=head[u]; now!=-1; now=e[now].next)
	{
	    int v=e[now].v;
	    if (e[now].cap>0&&dis[v]>dis[u]+e[now].cost)
	    {
		pre[v]=now;
		dis[v]=dis[u]+e[now].cost;
		if (!vis[v])
		{
		    vis[v]=1;
		    q.push(v);
		}
	    }
	}
	vis[u]=0;
    }
    return (dis[T]<inf);
}

int mincost()
{
    int cost=0,maxflow=0;
    while (spfa())
    {
	int nec=inf;
	for (int now=pre[T]; now!=-1; now=pre[e[now].u])
	    nec=std::min(nec,e[now].cap);
	for (int now=pre[T]; now!=-1; now=pre[e[now].u])
	{
	    e[now].cap-=nec;
	    e[now^1].cap+=nec;
	}
	maxflow+=nec;
	cost+=nec*dis[T];
    }
    if (maxflow==2) return cost;
    else return -1;
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	memset(head,-1,sizeof(head));
	cnt=0; S=n; T=n+1;
	addedge(S,0,2,0); addedge(n-1,T,2,0);
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    addedge(u,v,1,w);
	}
	int ans=mincost();
	if (ans==-1) printf("Instance #%d: Not possible\n",++cas);
	else printf("Instance #%d: %d\n",++cas,ans);
    }
    return 0;
}
