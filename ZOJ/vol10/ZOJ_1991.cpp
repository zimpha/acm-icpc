#include <cstdio>
#include <cstring>

const int MAXN=405;

bool map[MAXN][MAXN];
bool dp[MAXN][MAXN];
int sum[MAXN][2];
int col[MAXN];
int n, m;

bool dfs(int u, int flag)
{
	col[u]=((flag)?m:-m);
	sum[m][flag]++;
	for (int i=1; i<=n; i++)
		if (map[u][i])
		{
			if (col[u]==col[i]||(!col[i]&&!dfs(i,flag^1))) return false;
		}
	return true;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		memset(map,0,sizeof(map));
		while (m--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			v+=n;
			map[v][u]=map[u][v]=true;
		}
		m=0; n*=2;
		bool flag=true;
		memset(sum,0,sizeof(sum));
		memset(col,0,sizeof(col));
		for (int i=1; i<=n; i++)
			if (!col[i])
			{
				int tag=0;
				m++;
				if (i>n/2) tag=1;
				if (!dfs(i,tag)) flag=false;
			}
		if (!flag) printf("0\n");
		else
		{
			memset(dp,0,sizeof(dp));
			dp[0][0]=true;
			for (int i=1; i<=m; i++)
				for (int j=n/2; j>=0; j--)
					for (int k=n/2; k>=0; k--)
					{
						if (j>=sum[i][0]&&k>=sum[i][1])
							dp[j][k]|=dp[j-sum[i][0]][k-sum[i][1]];
					}
			int ret=n/4;
			for (; ret>=0; ret--)
				if (dp[ret][ret]) break;
			printf("%d\n", ret);
		}
	}
	return 0;
}
