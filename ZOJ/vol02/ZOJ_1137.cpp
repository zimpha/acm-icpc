#include <cstdio>
#include <cstring>

const int MAXN=505;

bool g[MAXN][MAXN];
bool vis[MAXN];
int match[MAXN];
int n;

bool find(int u)
{
    for (int v=0; v<n; v++)
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
    while (scanf("%d",&n)==1)
    {
	memset(g,0,sizeof(g));
	for (int i=0; i<n; i++)
	{
	    int u,v,m;
	    scanf("%d:",&u); getchar();
	    scanf("(%d)",&m);
	    while (m--)
	    {
		scanf("%d",&v);
		g[u][v]=1;
	    }
	}
	memset(match,0,sizeof(match));
	int ans=0;
	for (int i=0; i<n; i++)
	{
	    memset(vis,0,sizeof(vis));
	    if (find(i)) ans++;
	}
	printf("%d\n",n-ans/2);
    }
    return 0;
}
