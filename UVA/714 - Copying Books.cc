#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 505;
const int MAXM = 505;
const LL inf = 1ll<<60ll;

LL dp[MAXN][MAXM], sum[MAXN], limit;
int book[MAXN], n, m;

void print(int n, int m, LL upper)
{
	if (m==0) return;
	if (upper>=book[n]&&n>=m)
	{
		print(n-1,m,upper-book[n]);
		if (n>1) printf(" ");
		printf("%d", book[n]);
	}
	else 
	{
		print(n,m-1,limit);
		if (m>1) printf(" /");
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		sum[0]=0;
		for (int i=1; i<=n; i++)
		{
			scanf("%d", book+i);
			sum[i]=sum[i-1]+book[i];
		}
		memset(dp,-1,sizeof(dp));
		dp[0][0]=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=i&&j<=m; j++)
			{
				LL ret=inf;
				for (int k=j-1; k<i; k++)
					if (dp[k][j-1]!=-1)
						ret=min(ret,max(dp[k][j-1],sum[i]-sum[k]));
				dp[i][j]=ret;
			}
		limit=dp[n][m];
		print(n,m,limit);
		printf("\n");
	}
	return 0;
}
