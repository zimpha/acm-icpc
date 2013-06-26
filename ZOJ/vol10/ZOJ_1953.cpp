#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;

char s[MAXN], t[MAXN];
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
int n, m;

int main()
{
	while (scanf("%s%s", s+1, t+1)==2)
	{
		memset(dp,0,sizeof(dp));
		n=strlen(s+1); m=strlen(t+1);
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				if (s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
		int ret=dp[n][m]+1;
		int i=n, j=m, l=ret-1;
		while (l)
		{
			if (s[i]==t[j]) 
			{
				a[l]=i; b[l]=j;
				i--; j--; l--;
			}
			else 
			{
				if (dp[i-1][j]>dp[i][j-1]) i--;
				else j--;
			}
		}
		a[0]=b[0]=0;
		a[ret]=n+1; b[ret]=m+1;
		for (int i=1; i<=ret; i++)
		{
			for (int j=a[i-1]+1; j<a[i]; j++) putchar(s[j]);
			for (int j=b[i-1]+1; j<b[i]; j++) putchar(t[j]);
			if (i<ret) putchar(s[a[i]]);
		}
		puts("");
	}
	return 0;
}
