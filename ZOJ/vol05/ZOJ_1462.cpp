#include <cstdio>
#include <cstring>

const int MAXN=105;
const int inf=10000000;

bool g[MAXN][MAXN];
bool ans[MAXN];
int p[MAXN][MAXN];
int f[MAXN][MAXN];
int sum[MAXN][2];
int vis[MAXN];
int ret[MAXN];
int n, m;

void initial()
{
	memset(g,0,sizeof(g));
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		int x;
		while (scanf("%d", &x)==1&&x)
		{
			g[i][x]=true;
		}
	}
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			g[i][j]=g[j][i]=!(g[i][j]&&g[j][i]);
}

bool dfs(int u, int col)
{
	vis[u]=(col)?m:-m;
	sum[m][col]++;
	for (int v=1; v<=n; v++)
		if (g[u][v])
			if (vis[u]==vis[v]||(!vis[v]&&!dfs(v,col^1))) return false;
	return true;
}

bool color()
{
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	m=0;
	for (int i=1; i<=n; i++)
		if (!vis[i])
		{
			m++;
			if (!dfs(i,0)) return false;
		}
	return true;
}

void dp()
{
	memset(p,-1,sizeof(p));
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			f[i][j]=-inf;
	for (int j=0; j<=n/2; j++) 
		f[0][j]=0;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=n/2; j++)
			if (sum[i][1])
			{
				if (j>=sum[i][0])
				{
					f[i][j]=f[i-1][j-sum[i][0]]+sum[i][0];
					p[i][j]=0;
				}
				if (j>=sum[i][1]&&f[i-1][j-sum[i][1]]+sum[i][1]>f[i][j])
				{
					f[i][j]=f[i-1][j-sum[i][1]]+sum[i][1];
					p[i][j]=1;
				}
			}
			else
			{
				f[i][j]=f[i-1][j]; p[i][j]=-1;
				if (j>=sum[i][0]&&f[i-1][j-sum[i][0]]+sum[i][0]>f[i][j])
				{
					f[i][j]=f[i-1][j-sum[i][0]]+sum[i][0];
					p[i][j]=0;
				}
			}
}

void print()
{
	memset(ans,0,sizeof(ans));
	memset(ret,0,sizeof(ret));
	int i=m, j=n/2;
	while (i)
	{
		ret[i]=p[i][j];
		if (ret[i]>-1) j-=sum[i][ret[i]];
		i--;
	}
	for (int i=1; i<=n; i++)
		if (vis[i]<0&&ret[-vis[i]]==0) ans[i]=true;
		else if (vis[i]>0&&ret[vis[i]]==1) ans[i]=true;
	printf("%d", f[m][n/2]);
	for (int i=1; i<=n; i++)
		if (ans[i]) printf(" %d", i);
	printf("\n%d",n-f[m][n/2]);
	for (int i=1; i<=n; i++)
		if (!ans[i]) printf(" %d", i);
	printf("\n");
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		initial();
		if (!color()) puts("No solution");
		else 
		{
			dp();
			print();
		}
		if (test) puts("");
	}
	return 0;
}
