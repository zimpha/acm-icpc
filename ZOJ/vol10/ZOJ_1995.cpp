#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;
const int inf=0x3f3f3f3f;

int dp[MAXN][MAXN];
int p[MAXN][MAXN];
int h[MAXN];
int n, m;

void print(int n, int m)
{
	if (p[n][m]!=-1)
	{
		print(n-1,p[n][m]);
		printf("%c", (p[n][m]>m)?'D':'U');
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", h+i);
		memset(dp,0x3f,sizeof(dp));
		memset(p,-1,sizeof(p));
		dp[0][0]=0;
		for (int i=1; i<=n; i++)
			for (int j=0; j<MAXN; j++)
			{
				if (j>=h[i]&&dp[i-1][j-h[i]]!=inf&&dp[i][j]>std::max(j,dp[i-1][j-h[i]]))
				{
					dp[i][j]=std::max(dp[i-1][j-h[i]],j);
					p[i][j]=j-h[i];
				}
				if (j+h[i]<MAXN&&dp[i-1][j+h[i]]!=inf&&dp[i][j]>std::max(j,dp[i-1][j+h[i]]))
				{
					dp[i][j]=std::max(j,dp[i-1][j+h[i]]);
					p[i][j]=j+h[i];
				}
			}
		if (dp[n][0]==inf) printf("IMPOSSIBLE\n");
		else
		{
			print(n,0);
			puts("");
		}
	}
	return 0;
}
