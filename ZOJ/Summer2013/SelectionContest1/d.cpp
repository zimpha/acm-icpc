#include <cstdio>
#include <cstring>

const int MAXN=55;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

bool map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m;
int ret;

void dfs(int x, int y)
{
	vis[x][y]=true;
	for (int i=0; i<4; i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if (xx<0||yy<0||xx>n+1||yy>m+1) continue;
		if (!map[xx][yy]) ret++;
		if (map[xx][yy]&&!vis[xx][yy]) dfs(xx, yy);
	}
}

int main()
{
	while (scanf("%d%d", &n, &m)==2)
	{
		memset(map, 1, sizeof(map));
		for (int i=1; i<=n; i++)
		{
			getchar();
			for (int j=1; j<=m; j++)
			{
				char c=getchar();
				if (c=='#') map[i][j]=false;
			}
		}
		ret=0;
		memset(vis, 0, sizeof(vis));
		dfs(0, 0);
		printf("%d\n", ret);
	}
	return 0;
}
