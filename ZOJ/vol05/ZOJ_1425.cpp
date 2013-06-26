#include <cstdio>
#include <cstring>

const int MAXN=105;

int dp[MAXN][MAXN];
int a[MAXN], b[MAXN];
int pre[MAXN][MAXN][2];
int col[MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		for (int i=1; i<=n; i++) scanf("%d", a+i);
		for (int i=1; i<=m; i++) scanf("%d", b+i);
		memset(pre,0,sizeof(pre));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				for (int k=i-1; k>0; k--)
					if (b[j]==a[k])
					{
						pre[i][j][0]=k;
						break;
					}
				for (int k=j-1; k>0; k--)
					if (a[i]==b[k])
					{
						pre[i][j][1]=k;
						break;
					}
			}
		int ans=0;
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
			{
				if (a[i]!=b[j])
				{
					if (pre[i][j][0]!=0&&pre[i][j][1]!=0) 
						dp[i][j]=dp[pre[i][j][0]-1][pre[i][j][1]-1]+2;
				}
				if (dp[i][j]<dp[i-1][j-1]) dp[i][j]=dp[i-1][j-1];
				if (dp[i][j]<dp[i-1][j]) dp[i][j]=dp[i-1][j];
				if (dp[i][j]<dp[i][j-1]) dp[i][j]=dp[i][j-1];
				if (dp[i][j]>ans) ans=dp[i][j];
			}
		printf("%d\n", ans);
	}
	return 0;
}
