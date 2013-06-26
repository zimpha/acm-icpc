#include <cstdio>
#include <cstring>

const int MAXN=15;
const int MAXM=2005;

typedef long long LL;

LL dp[MAXN][MAXM];
int n, m;

int main()
{
	n=10; m=2000;
	memset(dp,0,sizeof(dp));
	for (int j=1; j<=m; j++)
		dp[1][j]=j;
	for (int i=2; i<=n; i++)
		for (int j=1; j<=m; j++)
			dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
	int test;
	scanf("%d", &test);
	for (int cas=1; cas<=test; cas++)
	{
		scanf("%d%d", &n, &m);
		printf("Case %d: n = %d, m = %d, # lists = %lld\n", cas, n, m, dp[n][m]);
	}
	return 0;
}
