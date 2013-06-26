#include <cstdio>
#include <cstring>

const int MAXN=51;

double dp[MAXN][MAXN];
double sum[MAXN];
int n;

int main()
{
	memset(dp,0,sizeof(dp));
	dp[1][1]=1.0; sum[1]=1.0;
	for (int i=2; i<MAXN; i++)
	{
		sum[i]=0;
		for (int j=1; j<=i; j++)
		{
			dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];
			sum[i]+=dp[i][j];
		}
	}
	while (scanf("%d", &n)==1&&n)
	{
		printf("%d %.0f\n", n, sum[n]);
	}
	return 0;
}
