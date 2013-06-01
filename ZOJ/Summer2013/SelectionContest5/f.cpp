#include <cstdio>
#include <cstring>

const int MAXN=10005;
const int MAXV=30;

typedef long long LL;

LL dp[MAXN];
int val[MAXV];
int n, v;

int main()
{
	while (scanf("%d%d", &v, &n)==2)
	{
		for (int i=0; i<v; i++)
			scanf("%d", val+i);
		memset(dp, 0, sizeof(dp));
		dp[0]=1LL;
		for (int i=0; i<v; i++)
			for (int j=val[i]; j<=n; j++)
				dp[j]+=dp[j-val[i]];
		printf("%lld\n", dp[n]);
	}
	return 0;
}
