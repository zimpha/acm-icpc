#include <cstdio>
#include <cstring>

const int MAXN=10005;
const int MAXM=105;

bool dp[MAXN][MAXM];
int a[MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", a+i);
	memset(dp,0,sizeof(dp));
	dp[0][0]=true;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (dp[i][j])
			{
				dp[i+1][((j+a[i+1])%m+m)%m]=true;
				dp[i+1][((j-a[i+1])%m+m)%m]=true;
			}
	if (dp[n][0]) printf("Divisible\n");
	else printf("Not divisible\n");
		if (test) puts("");
	}
	return 0;
}
