#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int R=101;
const int C=101;
const int dx[]={-1, 0, 0, 1};
const int dy[]={0, -1, 1, 0};

queue<pair<int , int > > q;
bool grid[R+1][C+1];
bool vis[R+1][C+1];
int N;

int main()
{
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	scanf("%d", &N);
	memset(grid, 1, sizeof(grid));
	while (N--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		grid[x][y]=false;
	}
	int ret=0;
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) q.pop();
	q.push(make_pair(0, 0));
	vis[0][0]=true;
	while (!q.empty())
	{
		pair<int, int> now;
		now=q.front(); q.pop();
		for (int k=0; k<4; k++)
		{
			int x=now.first+dx[k];
			int y=now.second+dy[k];
			if (x<0||x>R||y<0||y>R) continue;
			if (vis[x][y]) continue;
			if (!grid[x][y]) ret++;
			else 
			{
				q.push(make_pair(x, y));
				vis[x][y]=true;
			}
		}
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
