#include <cstdio>
#include <cstring>

const int MAXN=15;
const int MAXM=50000;

int dp[MAXM], val[MAXN], pro[MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		int year;
		scanf("%d%d%d", &m, &year, &n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d%d", val+i, pro+i);
			val[i]/=1000;
		}
		memset(dp,0,sizeof(dp));
		while (year--)
		{
			for (int i=1; i<=n; i++)
				for (int j=val[i]; j<=m/1000; j++)
					if (dp[j]<dp[j-val[i]]+pro[i])
						dp[j]=dp[j-val[i]]+pro[i];
			m+=dp[m/1000];
		}
		printf("%d\n", m);
	}
	return 0;
}
