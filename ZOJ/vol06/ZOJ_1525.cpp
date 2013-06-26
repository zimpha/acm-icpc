#include <cstdio>
#include <cstring>

const int MAXN=125;

bool g[MAXN][MAXN];
bool vis[MAXN];
int match[MAXN];
int n,m;

bool find(int u)
{
    for (int v=1; v<=n; v++)
	if (g[u][v]&&!vis[v])
	{
	    vis[v]=1;
	    if (!match[v]||find(match[v]))
	    {
		match[v]=u;
		return true;
	    }
	}
    return false;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	while (m--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    g[u][v]=1;
	}
	memset(match,0,sizeof(match));
	int ans=0;
	for (int i=1; i<=n; i++)
	{
	    memset(vis,0,sizeof(vis));
	    if (find(i)) ans++;
	}
	printf("%d\n",n-ans);
    }
    return 0;
}
