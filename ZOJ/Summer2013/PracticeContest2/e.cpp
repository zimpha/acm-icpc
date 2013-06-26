#include <cstdio>
#include <cstring>

const int MAXN=35;

long long dp[MAXN][MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; i++)
			dp[1][i]=1;
		for (int i=2; i<=n; i++)
			for (int j=0; j<=n-i+1; j++)
				for (int k=j; k<=n-i+2; k++)
					dp[i][j]+=dp[i-1][k];
		long long ans=0;
		for (int i=0; i<=n; i++)
			ans+=dp[n][i];
		printf("%lld\n", ans);
	}
	return 0;
}
