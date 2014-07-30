#include <cstdio>
#include <cstring>

const int MAXN=105;

int map[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m;

void search(int x, int y)
{
	if (dp[x][y]>-1) return;
	dp[x][y]=map[x][y];
	int res=0, xx, yy;
	for (int i=1; i<=m; i++)
	{
		xx=x+i;
		if (xx<n&&map[xx][y]>map[x][y])
		{
			search(xx,y);
			if (dp[xx][y]>res) res=dp[xx][y];
		}
		xx=x-i;
		if (xx>=0&&map[xx][y]>map[x][y])
		{
			search(xx,y);
			if (dp[xx][y]>res) res=dp[xx][y];
		}
		yy=y+i;
		if (yy<n&&map[x][yy]>map[x][y])
		{
			search(x,yy);
			if (dp[x][yy]>res) res=dp[x][yy];
		}
		yy=y-i;
		if (yy>=0&&map[x][yy]>map[x][y])
		{
			search(x,yy);
			if (dp[x][yy]>res) res=dp[x][yy];
		}
	}
	dp[x][y]+=res;
}

int main()
{
	while (scanf("%d%d", &n, &m)==2&&n>0)
	{
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				scanf("%d", &map[i][j]);
		memset(dp,-1,sizeof(dp));
		search(0,0);
		printf("%d\n", dp[0][0]);
	}
	return 0;
}
