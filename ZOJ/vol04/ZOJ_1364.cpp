#include <cstdio>
#include <cstring>

const int MAXN=105;

bool g[MAXN][MAXN];
bool vis[MAXN];
int match[MAXN];
int n,m,k;

bool find(int u)
{
    for (int i=0; i<m; i++)
	if (!vis[i]&&g[u][i])
	{
	    vis[i]=1;
	    if (match[i]==0||find(match[i]))
	    {
		match[i]=u;
		return true;
	    }
	}
    return false;
}

int main()
{
    while (scanf("%d",&n)==1&&n)
    {
	scanf("%d%d",&m,&k);
	memset(g,0,sizeof(g));
	for (int i=0; i<k; i++)
	{
	    int u,v;
	    scanf("%d%d%d",&i,&u,&v);
	    if (u&&v) g[u][v]=1;
	}
	int ans=0;
	memset(match,0,sizeof(match));
	for (int i=0; i<n; i++)
	{
	    memset(vis,0,sizeof(vis));
	    if (find(i)) ans++;
	}
	printf("%d\n",ans);
    }
    return 0;
}
