#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

const int MAXN=103;
const int inf=100000000;

int g[MAXN][MAXN];
int n,m,t;

int main()
{
    int cas=0;
    while (scanf("%d%d%d",&n,&m,&t)&&n)
    {
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=n; j++)
		g[i][j]=inf;
	while (m--)
	{
	    int u,v,w;
	    scanf("%d%d%d",&u,&v,&w);
	    g[u][v]=g[v][u]=w;
	}
	for (int k=1; k<=n; k++)
	    for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		    g[i][j]=min(g[i][j],max(g[i][k],g[k][j]));
	if (cas>0) printf("\n");
	printf("Case #%d\n",++cas);
	while (t--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    if (g[u][v]==inf) printf("no path\n");
	    else printf("%d\n",g[u][v]);
	}
    }
    return 0;
}
