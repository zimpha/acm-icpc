#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;

const int MAXN=1005;
const int inf=100000000;

int dp[MAXN][MAXN];
int t[MAXN];
int n, l, c;

int w(int t)
{
	if (t==0) return 0;
	else if (t<=10) return -c;
	else return (t-10)*(t-10);
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
	int cas=0;
	while (scanf("%d", &n)==1&&n)
	{
		if (cas++) printf("\n");
		scanf("%d%d", &l, &c);
		for (int i=1; i<=n; i++)
			scanf("%d", t+i);
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				dp[i][j]=inf;
		dp[0][0]=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=i; j++)
			{
				int sum=t[i];
				int ret=inf;
				for (int k=i-1; k>=j-1; k--)
				{
					if (dp[k][j-1]!=inf)
						ret=min(ret,dp[k][j-1]+w(l-sum));
					sum+=t[k];
					if (sum>l) break;
				}
				dp[i][j]=ret;
			}
		int ret;
		for (ret=1; ret<=n; ret++)
			if (dp[n][ret]!=inf) break;
		printf("Case %d:\n\n", cas);
		printf("Minimum number of lectures: %d\n", ret);
		printf("Total dissatisfaction index: %d\n", dp[n][ret]);
	}
	if (test) puts("");
	}
	return 0;
}
