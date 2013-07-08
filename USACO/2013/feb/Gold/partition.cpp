#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=20;
const int inf=1000000;

int cost[MAXN][MAXN];
int grid[MAXN][MAXN];
int dp[MAXN][MAXN];
int sum[MAXN];
int N, K;

int main()
{
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &grid[i][j]);
	int ret=inf;
	for (int mask=0; mask<(1<<(N-1)); mask++)
	{
		int k1=0;
		for (int i=0; i<N; i++)
			k1+=((mask>>i)&1);
		if (k1<=K)
		{
			for (int i=0; i<N; i++)
			{
				memset(sum, 0, sizeof(sum));
				for (int j=i+1; j<=N; j++)
				{
					cost[i][j]=0;
					int tmp=0;
					for (int k=0; k<N; k++)
					{
						sum[k]+=grid[j-1][k];
						tmp+=sum[k];
						cost[i][j]=max(cost[i][j], tmp);
						if ((mask>>k)&1) tmp=0;
					}
				}
			}
			for (int k2=0; k2<=N; k2++)
				for (int i=0; i<=N; i++)
					dp[k2][i]=inf;
			dp[0][0]=0;
			for (int k2=1; k2<=N && k2<=(K-k1+1); k2++)
			{
				for (int i=0; i<N; i++)
					for (int j=i+1; j<=N; j++)
						dp[k2][j]=min(dp[k2][j], max(dp[k2-1][i], cost[i][j]));
				ret=min(ret, dp[k2][N]);
			}
		}
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
