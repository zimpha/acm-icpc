#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=400;
const int MAXM=1005;

struct node
{
	int l, r, w;
};

node app[MAXM];
int dp[MAXN][MAXN];
int n;

bool cmp(node a, node b)
{
	return (a.r<b.r);
}

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=1; i<=n; i++)
			scanf("%d%d%d", &app[i].l, &app[i].r, &app[i].w);
		std::sort(app+1,app+n+1,cmp);
		memset(dp,0,sizeof(dp));
		for (int i=1; i<=n; i++)
		{
			//abandon
			for (int j=app[i-1].r+1; j<=app[i].r; j++)
				for (int k=0; k<=app[i].r; k++)
				{
					dp[j][k]=dp[j-1][k];
					dp[k][j]=dp[k][j-1];
				}
			//use
			for (int j=app[i].r; j>=0; j--)
			{
				dp[app[i].r][j]=std::max(dp[app[i].r][j],dp[app[i].l-1][j]+app[i].w);
				dp[j][app[i].r]=std::max(dp[j][app[i].r],dp[j][app[i].l-1]+app[i].w);
			}
		}
		printf("%d\n", dp[app[n].r][app[n].r]);
	}
	return 0;
}
