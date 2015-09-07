#include <cstdio>
#include <cstring>
#include <queue>

const int size=1<<20;
const int MAXM=105;
const int inf=1000000000;

struct patchtype
{
    int B0,B1;
    int F0,F1;
    int time;
};

patchtype patch[MAXM];
bool vis[size];
int dis[size];
int n,m,S;

void spfa()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=0; i<(1<<n); i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    q.push(S); dis[S]=0; vis[S]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (int i=1; i<=m; i++)
	    if (((~u&patch[i].B1)==0)&&((u&patch[i].B0)==0))
	    {
		int v=u&(~patch[i].F0)|patch[i].F1;
		if (dis[v]>dis[u]+patch[i].time)
		{
		    dis[v]=dis[u]+patch[i].time;
		    if (!vis[v])
		    {
			q.push(v);
			vis[v]=1;
		    }
		}
	    }
	vis[u]=0;
    }
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	S=(1<<n)-1;
	for (int i=1; i<=m; i++)
	{
	    scanf("%d",&patch[i].time);
	    patch[i].B0=patch[i].B1=0;
	    patch[i].F0=patch[i].F1=0;
	    getchar();
	    for (int j=0; j<n; j++)
	    {	
		int c=getchar();
		if (c=='-') patch[i].B0+=1<<j;
		else if (c=='+') patch[i].B1+=1<<j;
	    }
	    getchar();
	    for (int j=0; j<n; j++)
	    {
		int c=getchar();
		if (c=='-') patch[i].F0+=1<<j;
		else if (c=='+') patch[i].F1+=1<<j;
	    }
	}
	spfa();
	printf("Product %d\n",++cas);
	if (dis[0]==inf) printf("Bugs cannot be fixed.\n\n");
	else printf("Fastest sequence takes %d seconds.\n\n",dis[0]);
    }
    return 0;
}

