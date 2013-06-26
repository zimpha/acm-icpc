#include <cstdio>
#include <cstring>

const int MAXN=2005;
const int inf=100000;

typedef char string[7];

int g[MAXN][MAXN];
string s[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n;

int diff(string a,string b)
{
    int sum=0;
    for (int i=0; i<7; i++)
	if (a[i]!=b[i]) sum++;
    return sum;
}

int prim()
{
    int minweight=0;
    for (int i=1; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    dis[1]=0;
    while (1)
    {
	int min=inf,u;
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
    while (scanf("%d",&n)==1&&n)
    {
	memset(g,0,sizeof(g));
	for (int i=1; i<=n; i++)
	{
	    scanf("%s",s[i]);
	    for (int j=1; j<i; j++)
		g[i][j]=g[j][i]=diff(s[i],s[j]);
	}
	printf("The highest possible quality is 1/%d.\n",prim());
    }
    return 0;
}
