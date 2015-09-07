#include <queue>
#include <cstdio>
#include <cstring>

const int MAXN=105;

bool map[MAXN][MAXN];
int deg[MAXN];
int ans[MAXN];
int n,m;

void topology()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++)
	if (!deg[i]) q.push(i);
    m=0;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	ans[m++]=u;
	for (int v=1; v<=n; v++)
	    if (map[u][v])
	    {
		deg[v]--;
		if (deg[v]==0) q.push(v);
	    }
    }
    for (int i=0; i<m; i++)
	printf("%d%c",ans[i],(i==m-1)?'\n':' ');
}

int main()
{
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	memset(map,0,sizeof(map));
	memset(deg,0,sizeof(deg));
	while (m--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    map[u][v]=1; deg[v]++;
	}
	topology();
    }
    return 0;
}
