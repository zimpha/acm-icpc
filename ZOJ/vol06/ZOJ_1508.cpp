#include <cstdio>
#include <cstring>
#include <queue>

using std::queue;

const int MAXN=50005;
const int inf=1000000000;

struct node
{
    int v,w;
    node *next;
};

node *head[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n,nodes;

void addedge(int u,int v,int w)
{
    node *p=new(node);
    p->v=v; p->w=w; p->next=head[u]; head[u]=p;
}

void spfa()
{
    queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<=nodes; i++)
    {
	dis[i]=-inf;
	vis[i]=0;
    }
    q.push(0); dis[0]=0; vis[0]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (node *p=head[u]; p; p=p->next)
	{
	    int v=p->v,w=p->w;
	    if (dis[v]<dis[u]+w)
	    {
		dis[v]=dis[u]+w;
		if (!vis[v])
		{
		    vis[v]=1;
		    q.push(v);
		}
	    }
	}
	vis[u]=0;
    }
}

int main()
{
    while (scanf("%d",&n)==1)
    {
    nodes=0;
    memset(head,0,sizeof(head));
    while (n--)
    {
	int u,v,w;
	scanf("%d%d%d",&u,&v,&w);
	if (v+1>nodes) nodes=v+1;
	addedge(u,v+1,w);
    }
    for (int i=0; i<nodes; i++)
    {
	addedge(i,i+1,0);
	addedge(i+1,i,-1);
    }
    spfa();
    printf("%d\n",dis[nodes]);
    }
    return 0;
}
