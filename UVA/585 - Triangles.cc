#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=205;

char map[MAXN][MAXN];
int dp[MAXN][MAXN];
int n;

int main()
{
	int cas=0;
	while (scanf("%d", &n)==1&&n)
	{
		memset(map,0,sizeof(map));
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=i; j++)
				getchar();
			for (int j=1; j<=2*(n-i)+1; j++)
				map[i][j]=getchar();
		}
		memset(dp,0,sizeof(dp));
		int ret=0;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=2*(n-i)+1; j+=2)
				if (map[i][j]=='-')
				{
					dp[i][j]=1;
					if (map[i-1][j+1]=='-') dp[i][j]+=std::min(dp[i-1][j],dp[i-1][j+2]);
					ret=std::max(ret,dp[i][j]);
				}
		memset(dp,0,sizeof(dp));
		for (int i=n; i>0; i--)
			for (int j=2; j<=2*(n-i)+1; j+=2)
				if (map[i][j]=='-')
				{
					dp[i][j]=1;
					if (map[i+1][j-1]=='-') dp[i][j]+=std::min(dp[i+1][j-2],dp[i+1][j]);
					ret=std::max(ret,dp[i][j]);
				}
		printf("Triangle #%d\n", ++cas);
		printf("The largest triangle area is %d.\n\n", ret*ret);
	}
	return 0;
}
