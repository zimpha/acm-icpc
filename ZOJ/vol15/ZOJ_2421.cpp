#include <cstdio>
#include <cstring>

const int MAXN=500001;

bool hash[MAXN*10];
int dp[MAXN];
int n;

int main()
{
	memset(hash,0,sizeof(hash));
	dp[0]=0; hash[0]=true;
	for (int i=1; i<MAXN; i++)
	{
		int tmp=dp[i-1]-i;
		if (tmp>0&&!hash[tmp]) dp[i]=tmp;
		else dp[i]=dp[i-1]+i;
		hash[dp[i]]=true;

	}
	while (scanf("%d", &n)==1&&n>=0)
	{
		printf("%d\n", dp[n]);
	}
	return 0;
}
