#include <cstdio>
#include <cstring>

const int MAXN=55;
const int MAXM=1005;
const int MAXB=25;

int dp[MAXN][MAXM];
int w[MAXN][MAXB];
int b[MAXN];
int n, m;

int main()
{
	int cas=0;
	while (scanf("%d", &n)==1&&n)
	{
		if (cas) puts("");
		memset(w,0,sizeof(w));
		for (int i=1; i<=n; i++)
		{
			scanf("%d", b+i);
			for (int j=1; j<=b[i]; j++)
			{
				scanf("%d", &w[i][j]);
				w[i][j]+=w[i][j-1];
			}
		}
		memset(dp,-1,sizeof(dp));
		m=0; dp[0][0]=0;
		for (int i=1; i<=n; i++)
		{
			m+=b[i]; dp[i][0]=0;
			for (int j=1; j<=m; j++)
				for (int k=0; j>=k&&k<=b[i]; k++)
					if (dp[i-1][j-k]!=-1&&dp[i][j]<dp[i-1][j-k]+k*10-w[i][k])
						dp[i][j]=dp[i-1][j-k]+k*10-w[i][k];
		}
		int ret=0;
		for (int i=0; i<=m; i++)
			if (dp[n][i]>ret) ret=dp[n][i];
		printf("Workyards %d\n", ++cas);
		printf("Maximum profit is %d.\n", ret);
		int count=0;
		printf("Number of pruls to buy:");
		for (int i=0; i<=m; i++)
			if (dp[n][i]==ret)
			{
				count++;
				printf(" %d", i);
				if (count==10) break;
			}
		puts("");
	}
	return 0;
}
