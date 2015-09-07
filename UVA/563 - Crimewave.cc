#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=5005;
const int MAXM=80000;
const int inf=10000000;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

struct node
{
    int v,cap,flow;
    int next;
};

node e[MAXM];
int head[MAXN],level[MAXN],work[MAXN];
int S,T,sum,cnt;

void addedge(int u,int v,int cap)
{
    e[cnt].v=v; e[cnt].cap=cap; e[cnt].flow=0;
    e[cnt].next=head[u]; head[u]=cnt++;
    e[cnt].v=u; e[cnt].cap=0; e[cnt].flow=0;
    e[cnt].next=head[v]; head[v]=cnt++;
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

bool dinic()
{
    int flow=0;
    while (dinic_bfs())
    {
	memcpy(work,head,sizeof(head));
	while (1)
	{
	    int tmp=dinic_dfs(S,inf);
	    if (tmp==0) break;
	    flow+=tmp;
	}
    }
    return (flow==sum);
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	int s,a,n;
	scanf("%d%d%d",&s,&a,&sum);
	memset(head,-1,sizeof(head));
	cnt=0; S=0; T=s*a*2+1; n=s*a;
	for (int i=1; i<=s; i++)
	    for (int j=1; j<=a; j++)
	    {
		int u=(i-1)*a+j;
		addedge(u,u+n,1);
		for (int k=0; k<4; k++)
		{
		    int x=i+dx[k],y=j+dy[k];
		    if (x>0&&x<=s&&y>0&&y<=a)
			addedge(u+n,(x-1)*a+y,1);
		}
	    }
	for (int i=1; i<=a; i++)
	{
	    addedge(i+n,T,1);
	    addedge((s-1)*a+i+n,T,1);
	}
	for (int i=2; i<s; i++)
	{
	    addedge((i-1)*a+n+1,T,1);
	    addedge(i*a+n,T,1);
	}
	for (int i=1; i<=sum; i++)
	{
	    int x,y;
	    scanf("%d%d",&x,&y);
	    addedge(S,(x-1)*a+y,1);
	}
	if (dinic()) printf("possible\n");
	else printf("not possible\n");
    }
    return 0;
}
