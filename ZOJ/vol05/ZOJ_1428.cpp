#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

const int MAXN=35;
const int inf=INT_MAX;

int dp[MAXN][MAXN][MAXN];
int d[MAXN][MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<n; i++)
			for (int j=i+1; j<=n; j++)
				scanf("%d", &d[i][j]);
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				for (int k=0; k<=n; k++)
					dp[i][j][k]=inf;
		dp[1][1][1]=0;
		for (int i=1; i<n; i++)
			for (int j=i; j<n; j++)
				for (int k=j; k<n; k++)
					if (dp[i][j][k]!=inf)
					{
						dp[i][j][k+1]=std::min(dp[i][j][k+1],dp[i][j][k]+d[k][k+1]);
						dp[i][k][k+1]=std::min(dp[i][k][k+1],dp[i][j][k]+d[j][k+1]);
						dp[j][k][k+1]=std::min(dp[j][k][k+1],dp[i][j][k]+d[i][k+1]);
					}
		int ret=inf;
		for (int i=1; i<n; i++)
			for (int j=i; j<n; j++)
				if (dp[i][j][n]<ret)
					ret=dp[i][j][n];
		printf("%d\n", ret);
	}
	return 0;
}
