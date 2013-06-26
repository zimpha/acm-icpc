#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;
using std::abs;

const int MAXN=205;

int tree[MAXN][MAXN];
int dp[MAXN][2];
bool vis[MAXN];
int w[MAXN];
int e[MAXN];
int n, m;

void dfs(int u)
{
	vis[u]=true;
	dp[u][0]=0; dp[u][1]=w[u];
	for (int i=1; i<=tree[u][0]; i++)
		if (!vis[tree[u][i]])
		{
			int v=tree[u][i];
			dfs(v);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
}

int main()
{
	while (scanf("%d%d", &n, &m)==2&&n)
	{
		w[0]=0;
		for (int i=1; i<=n; i++)
			scanf("%d", w+i);
		for (int i=1; i<=m; i++)
			scanf("%d", e+i);
		memset(tree,0,sizeof(tree));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
			{
				for (int k=1; k<=m; k++)
					if (abs(w[i]-w[j])==e[k])
					{
						tree[i][++tree[i][0]]=j;
						break;
					}
			}
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for (int i=1; i<=n; i++)
			if (!vis[i])
			{
				dfs(i);
				dp[0][0]+=max(dp[i][0],dp[i][1]);
			}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}
