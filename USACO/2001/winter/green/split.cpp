#include <map>
#include <cstdio>
#include <cstring>

const int MAXN=41;
const int SIZE=2005;

bool dp[2][SIZE][SIZE];
int milk[MAXN];
int N, sum;

int main()
{
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	scanf("%d", &N); sum=0;
	for (int i=1; i<=N; i++)
	{
		scanf("%d", &milk[i]);
		sum+=milk[i];
	}
	memset(dp, 0, sizeof(dp));
	sum=sum/2;
	dp[0][0][0]=1;
	for (int i=1; i<=N; i++)
	{
		for (int j=0; j<=sum; j++)
			for (int k=0; k<=sum; k++)
			{
				dp[i&1][j][k]|=dp[(i-1)&1][j][k];
				if (j>=milk[i]) dp[i&1][j][k]|=dp[(i-1)&1][j-milk[i]][k];
				if (k>=milk[i]) dp[i&1][j][k]|=dp[(i-1)&1][j][k-milk[i]];
			}
	}
	int ans;
	for (ans=sum; ans>=0; ans--)
		if (dp[N&1][ans][ans]) break;
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
