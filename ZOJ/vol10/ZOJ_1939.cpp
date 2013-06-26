#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;
const int SIZE=35;

typedef char str[SIZE];

str a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
int n, m;

void print(int i, int j, int len)
{
	if (len==0) return;
	if (!strcmp(a[i],b[j]))
	{
		print(i-1,j-1,len-1);
		printf("%s", a[i]);
		if (len==dp[n][m]) printf("\n");
		else printf(" ");
	}
	else 
	{
		if (dp[i-1][j]>dp[i][j-1]) print(i-1,j,len);
		else print(i,j-1,len);
	}
}

int main()
{
	n=m=1;
	while (scanf("%s", a[n])==1)
	{
		n++;
		while (scanf("%s", a[n])&&a[n][0]!='#') n++;
		while (scanf("%s", b[m])&&b[m][0]!='#') m++;
		n--; m--;
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				if (!strcmp(a[i],b[j])) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
		print(n, m, dp[n][m]);
		n=m=1;
	}
	return 0;
}
