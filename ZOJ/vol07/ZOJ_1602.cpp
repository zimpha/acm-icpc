#include <cstdio>
#include <cstring>
#include <climits>

const int MAXN=105;
const int inf=INT_MAX;

int dp[MAXN][MAXN];
int v[MAXN];
int n;

void calc(int l, int r)
{
	if (dp[l][r]!=-1) return;
	if (l+1==r) 
	{
		dp[l][r]=0;
		return;
	}
	if (l+2==r) 
	{
		dp[l][r]=v[l]*v[l+1]*v[r];
		return;
	}
	int ret=inf;
	for (int k=l+1; k<r; k++)
	{
		calc(l,k); calc(k,r);
		if (ret>dp[l][k]+dp[k][r]+v[l]*v[k]*v[r])
			ret=dp[l][k]+dp[k][r]+v[l]*v[k]*v[r];
	}
	dp[l][r]=ret;
}

int main()
{
	while (scanf("%d", &n)==1)
	{
	for (int i=0; i<n; i++)
		scanf("%d", v+i);
	memset(dp,-1,sizeof(dp));
	calc(0,n-1);
	printf("%d\n", dp[0][n-1]);
	}
	return 0;
}
