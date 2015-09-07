#include <cstdio>
#include <cstring>

const int MAXN=105;
const int MAXM=205;
const int inf=1000000000;

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
    while (scanf("%d",&n)==1&&n)
    {
	scanf("%d",&m);
	for (int i=0; i<m; i++)
	{
	    int si,ni,ki;
	    char oi[10];
	    scanf("%d %d %s %d",&si,&ni,oi,&ki);
	    if (oi[0]=='g') e[i].u=si+ni,e[i].v=si-1,e[i].w=-(ki+1);
	    else e[i].u=si-1,e[i].v=si+ni,e[i].w=ki-1;
	}
	if (!Bellman()) printf("successful conspiracy\n");
	else printf("lamentable kingdom\n");
    }
    return 0;
}
