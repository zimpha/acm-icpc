#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;
const int MAXM=10000;
const int inf=100000000;

struct node
{
    int v,cap,flow;
    int next;
};

int head[MAXN],work[MAXN];
int level[MAXN];
node e0[MAXM],e[MAXM];
int n,m,S,T;
int cnt;

void addedge(int u,int v,int cap)
{
    e0[cnt].v=v; e0[cnt].cap=cap; e0[cnt].flow=0; e0[cnt].next=head[u]; head[u]=cnt++;
    e0[cnt].v=u; e0[cnt].cap=0; e0[cnt].flow=0; e0[cnt].next=head[v]; head[v]=cnt++;
}

bool dinic_bfs()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    memset(level,0,sizeof(level));
    q.push(S); level[S]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (int now=head[u]; now!=-1; now=e[now].next)
	{
	    int v=e[now].v;
	    if (!level[v]&&e[now].cap>e[now].flow)
	    {
		level[v]=level[u]+1;
		q.push(v);
	    }
	}
    }
    return (level[T]>0);
}

int dinic_dfs(int u,int low)
{
    if (u==T) return low;
    for (int &now=work[u]; now!=-1; now=e[now].next)
    {
	int v=e[now].v;
	if (level[v]==level[u]+1&&e[now].cap>e[now].flow)
	{
	    int tmp=dinic_dfs(v,std::min(low,e[now].cap-e[now].flow));
	    if (tmp>0)
	    {
		e[now].flow+=tmp;
		e[now^1].flow-=tmp;
		return tmp;
	    }
	}
    }
    return 0;
}

int dinic()
{
    int maxflow=0;
    while (dinic_bfs())
    {
	memcpy(work,head,sizeof(head));
	while (1)
	{
	    int tmp=dinic_dfs(S,inf);
	    if (tmp==0) break;
	    maxflow+=tmp;
	}
    }
    return maxflow;
}

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
	memset(head,-1,sizeof(head));
	cnt=0;
	for (int i=0; i<n; i++) addedge(i,i+n,1);
	while (m--)
	{
	    int u,v;
	    scanf(" (%d,%d)",&u,&v);
	    addedge(u+n,v,inf);
	    addedge(v+n,u,inf);
	}
	int ans=inf;
	for (int i=0; i<n; i++)
	    for (int j=i+1; j<n; j++)
	    {
		S=i+n; T=j;
		memcpy(e,e0,sizeof(e0));
		ans=std::min(ans,dinic());
	    }
	if (ans>n) ans=n;
	printf("%d\n",ans);
    }
    return 0;
}
