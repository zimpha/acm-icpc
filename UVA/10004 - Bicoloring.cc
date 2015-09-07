#include <cstdio>
#include <cstring>

const int MAXN=200;

bool map[MAXN][MAXN];
int col[MAXN];
int n;

bool dfs(int u, int color)
{
    col[u]=color;
    for (int v=0; v<n; v++)
	if (map[u][v])
	{
	    if (col[u]==col[v]) return false;
	    if (col[v]==-1&&!dfs(v,1-color)) return false;
	}
    return true;
}

int main()
{
    while (scanf("%d",&n)==1&&n)
    {
	int m;
	scanf("%d",&m);
	memset(map,0,sizeof(map));
	while (m--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    map[u][v]=map[v][u]=1;
	}
	memset(col,-1,sizeof(col));
	if (dfs(0,0)) printf("BICOLORABLE.\n");
	else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
