#include <cstdio>
#include <cstring>

const int MAXP=105;
const int MAXN=305;

bool g[MAXP][MAXN];
bool vis[MAXN];
int match[MAXN];
int n,p;

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
	scanf("%d%d",&p,&n);
	memset(g,0,sizeof(g));
	for (int i=1; i<=p; i++)
	{
	    int m,v;
	    scanf("%d",&m);
	    while (m--)
	    {
		scanf("%d",&v);
		g[i][v]=1;
	    }
	}
	memset(match,0,sizeof(match));
	int ans=0;
	for (int i=1; i<=p; i++)
	{
	    memset(vis,0,sizeof(vis));
	    if (find(i)) ans++;
	}
	if (ans==p) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
