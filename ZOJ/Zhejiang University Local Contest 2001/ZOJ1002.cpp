#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=4;

int map[MAXN][MAXN];
int N, ans;

int cnt()
{
	int ret=0;
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (map[i][j]==0) ret++;
	return ret;
}

void add(int x, int y, int d)
{
	map[x][y]+=d;
	for (int i=x+1; i<N&&map[i][y]!=-1; i++) map[i][y]+=d;
	for (int i=x-1; i>=0&&map[i][y]!=-1; i--) map[i][y]+=d;
	for (int j=y+1; j<N&&map[x][j]!=-1; j++) map[x][j]+=d;
	for (int j=y-1; j>=0&&map[x][j]!=-1; j--) map[x][j]+=d;
}

void dfs(int ret)
{
	if (cnt()==0)
	{
		if (ret>ans) ans=ret;
		return;
	}
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
		{
			if (map[i][j]!=0) continue;
			add(i, j, 1);
			dfs(ret+1);
			add(i, j, -1);
		}
}

int main()
{
	while (scanf("%d", &N)==1&&N)
	{
		int sum=0;
		for (int i=0; i<N; i++)
		{
			getchar();
			for (int j=0; j<N; j++)
			{
				char c=getchar();
				if (c=='X') map[i][j]=-1;
				else map[i][j]=0, sum++;
			}
		}
		ans=0; dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}
