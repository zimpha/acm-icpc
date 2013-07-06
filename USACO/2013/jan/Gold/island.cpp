#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 20
#define MAXG 55
#define MAXS 35000
#define INF 100000000

struct node
{
	int x, y, d;
};

const int dx[]={-1, 0, 0, 1};
const int dy[]={0, -1, 1, 0};

char grid[MAXG][MAXG];
int group[MAXG][MAXG];
int tdist[MAXG][MAXG];
int dist[MAXN][MAXN];
int dp[MAXS][MAXN];
queue<node> q;
int N, R, C;

void floodfill(int x, int y)
{
	group[x][y]=N;
	for (int k=0; k<4; k++)
	{
		int xx=x+dx[k];
		int yy=y+dy[k];
		if (grid[xx][yy]=='X'&&group[xx][yy]==-1)
			floodfill(xx, yy);
	}
}

void calc_islands()
{
	memset(group, -1, sizeof(group));
	N=0;
	for (int i=1; i<=R; i++)
		for (int j=1; j<=C; j++)
			if (grid[i][j]=='X'&&group[i][j]==-1)
			{
				floodfill(i, j);
				N++;
			}
}

void calc_dist()
{
	memset(dist, 63, sizeof(dist));
	for (int i=0; i<N; i++)
	{
		node now, tmp;
		bool flag=false;
		for (int x=1; x<=R&&!flag; x++)
			for (int y=1; y<=C&&!flag; y++)
				if (group[x][y]==i)
				{
					now.x=x, now.y=y;
					flag=true;
				}
		memset(tdist, 63, sizeof(tdist));
		while (!q.empty()) q.pop();
		now.d=0; q.push(now);
		tdist[now.x][now.y]=0;
		while (!q.empty())
		{
			now=q.front(); q.pop();
			if (group[now.x][now.y]!=-1)
			{
				if (now.d<dist[i][group[now.x][now.y]])
					dist[i][group[now.x][now.y]]=now.d;
			}
			for (int k=0; k<4; k++)
			{
				tmp.x=now.x+dx[k];
				tmp.y=now.y+dy[k];
				tmp.d=now.d;
				if (grid[tmp.x][tmp.y]=='X')
				{
					if (tmp.d<tdist[tmp.x][tmp.y])
					{
						tdist[tmp.x][tmp.y]=tmp.d;
						q.push(tmp);
					}
				}
				else if (grid[tmp.x][tmp.y]=='S')
				{
					tmp.d++;
					if (tmp.d<tdist[tmp.x][tmp.y])
					{
						tdist[tmp.x][tmp.y]=tmp.d;
						q.push(tmp);
					}
				}
			}
		}
	}
}

void calc_tsp()
{
	memset(dp, 63, sizeof(dp));
	for (int i=0; i<N; i++)
		dp[1<<i][i]=0;
	for (int s=0; s<(1<<N); s++)
		for (int i=0; i<N; i++)
			if (s&(1<<i))
			{
				for (int j=0; j<N; j++)
					if (!(s&(1<<j)))
						if (dp[s][i]+dist[i][j]<dp[s|(1<<j)][j])
							dp[s|(1<<j)][j]=dp[s][i]+dist[i][j];
			}
	int ans=INF;
	for (int i=0; i<N; i++)
		if (dp[(1<<N)-1][i]<ans)
			ans=dp[(1<<N)-1][i];
	printf("%d\n", ans);
}

int main()
{
	freopen("island.in", "r", stdin);
	freopen("island.out", "w", stdout);
	
	memset(grid, '.', sizeof(grid));
	scanf("%d%d", &R, &C);
	for (int i=1; i<=R; i++)
		scanf("%s", &grid[i][1]);
	calc_islands();
	calc_dist();
	calc_tsp();

	fclose(stdin); fclose(stdout);
	return 0;
}
