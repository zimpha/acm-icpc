#include <queue>
#include <cstdio>
#include <cstring>

const int MAXN=20005;
const int inf=2000000005;

struct node
{
    int v,w;
    node *next;
};

node *head[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n,m,s,t;

void addedge(int u,int v,int w)
{
    node *p=new(node);
    p->v=v; p->w=w; p->next=head[u]; head[u]=p;
}

void spfa()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<n; i++)
    {
	dis[i]=inf; vis[i]=0;
    }
    q.push(s); dis[s]=0; vis[s]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (node *p=head[u]; p; p=p->next)
	{
	    int v=p->v, w=p->w;
	    if (dis[v]>dis[u]+w)
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
    int test;
    scanf("%d",&test);
    for (int cas=1; cas<=test; cas++)
    {
	scanf("%d%d%d%d",&n,&m,&s,&t);
	memset(head,0,sizeof(head));
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    addedge(u,v,w);
	    addedge(v,u,w);
	}
	spfa();
	printf("Case #%d: ",cas);
	if (dis[t]<inf) printf("%d\n",dis[t]);
	else printf("unreachable\n");
    }
    return 0;
}
