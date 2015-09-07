#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=205;
const int MAXM=50000;
const int inf=1000000000;

struct node
{
    int v,cap,flow;
    int next;
};

int head[MAXN],work[MAXN];
int level[MAXN];
node e[MAXM];
int n,m,cnt;
int S,T;

void addedge(int u,int v,int cap)
{
    e[cnt].v=v; e[cnt].cap=cap; e[cnt].flow=0; e[cnt].next=head[u]; head[u]=cnt++;
    e[cnt].v=u; e[cnt].cap=0; e[cnt].flow=0; e[cnt].next=head[v]; head[v]=cnt++;
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
    while (scanf("%d",&n)==1)
    {
	memset(head,-1,sizeof(head));
	S=0; T=n*2+1; cnt=0;
	for (int i=1; i<=n; i++)
	{
	    int tmp;
	    scanf("%d",&tmp);
	    addedge(i,i+n,tmp);
	}
	scanf("%d",&m);
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    addedge(u+n,v,w);
	}
	int b,d;
	scanf("%d%d",&b,&d);
	while (b--)
	{
	    scanf("%d",&m);
	    addedge(S,m,inf);
	}
	while (d--)
	{
	    scanf("%d",&m);
	    addedge(m+n,T,inf);
	}
	printf("%d\n",dinic());
    }
    return 0;
}
