#include <cstdio>
#include <cstring>

const int MAXN=2005;
const int inf=100000000;

typedef char string[25];

double g[MAXN][MAXN];
string s[MAXN];
bool vis[MAXN];
double dis[MAXN];
int n;

int getid(string a)
{
    for (int i=1; i<=n; i++)
	if (strcmp(a,s[i])==0) return i;
}

double prim()
{
    double minweight=0;
    for (int i=1; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    dis[1]=0;
    while (1)
    {
	double min=inf;
	int u;
	for (int i=1; i<=n; i++)
	    if (!vis[i]&&min>dis[i])
	    {
		min=dis[i];
		u=i;
	    }
	if (min==inf) break;
	minweight+=min; vis[u]=1;
	for (int v=1; v<=n; v++)
	    if (!vis[v]&&dis[v]>g[u][v])
		dis[v]=g[u][v];
    }
    return minweight;
}

int main()
{
    double tot;
    scanf("%lf%d",&tot,&n);
    for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	    g[i][j]=inf;
    for (int i=1; i<=n; i++) scanf("%s",s[i]);
    int m; scanf("%d",&m);
    while (m--)
    {
	int u,v;
	string a,b;
	scanf("%s%s",a,b);
	u=getid(a); v=getid(b);
	scanf("%lf",&g[u][v]);
	g[v][u]=g[u][v];
    }
    double ans=prim();
    if (ans<=tot) printf("Need %.1f miles of cable\n",ans);
    else printf("Not enough cable\n");
    return 0;
}
