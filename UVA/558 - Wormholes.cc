#include <cstdio>
#include <cstring>

const int MAXN=1005;
const int MAXM=2005;

struct node
{
    int u,v,w;
};

node e[MAXM];
int dis[MAXN];
int n,m;

bool Bellman()
{
    memset(dis,0,sizeof(dis));
    for (int i=1; i<=n; i++)
	for (int j=0; j<m; j++)
	    if (dis[e[j].v]>dis[e[j].u]+e[j].w)
		dis[e[j].v]=dis[e[j].u]+e[j].w;
    for (int j=0; j<m; j++)
	if (dis[e[j].v]>dis[e[j].u]+e[j].w) return false;
    return true;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++)
	    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	if (Bellman()) printf("not possible\n");
	else printf("possible\n");
    }
    return 0;
}
