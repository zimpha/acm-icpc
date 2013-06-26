#include <cstdio>
#include <cstring>

const int MAXN=15;
const int inf=100000000;
const int d[6][2]={-1,-1,-1,0,0,-1,0,1,1,1,1,0};

bool vis[MAXN][MAXN];
int map[MAXN][MAXN];
int n,c;

int ok(int x, int y)
{
	if (x>=1&&x<=n&&y>=1&&y<=x) return 1;
	return 0;
}

int remove(int x, int y, int &has0)
{
	if (!vis[x][y])
	{
		vis[x][y]=1;
		int sum=0;
		for (int i=0; i<6; i++)
		{
			int k=x+d[i][0], v=y+d[i][1];
			if (ok(k,v))
			{
				if (map[k][v]==map[x][y]) sum+=remove(k,v,has0);
				else if(!map[k][v]) has0=1;
			}
		}
		return 1+sum;
	}
	return 0;
}

int caculate(int c)
{
	memset(vis,0,sizeof(vis));
	int sum=0, has0=0, tmp=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=i; j++)
		{
			if (vis[i][j]) continue;
			has0=0;
			if (map[i][j])
			{
				tmp=remove(i,j,has0);
				if (!has0)
					if (map[i][j]==c) sum-=tmp;
					else sum+=tmp;
			}
		}
	}
	return sum;
}

int main()
{
	while (scanf("%d %d", &n, &c)==2&&n)
	{
		for (int i=1; i<=n; i++)
			for (int j=1; j<=i; j++)
				scanf("%d", &map[i][j]);
		int ret=-inf;
		for (int i=1; i<=n; i++)
			for (int j=1; j<=i; j++)
				if (map[i][j]==0)
				{
					map[i][j]=c;
					int tmp=caculate(c);
					map[i][j]=0;
					if (tmp>ret) ret=tmp;
				}
		printf("%d\n", ret);
	}
	return 0 ;
}