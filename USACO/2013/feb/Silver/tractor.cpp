#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=505;
const int dx[]={-1, 0, 0, 1};
const int dy[]={0, -1, 1, 0};

struct node
{
	int x, y;
};

node que[MAXN*MAXN];
bool vis[MAXN][MAXN];
int grid[MAXN][MAXN];
int N, M;

int calc_size(int sx, int sy, int D)
{
	int res=1, head=0, tail=0;
	node now, tmp;
	now.x=sx, now.y=sy;
	vis[sx][sy]=true; que[0]=now;
	while (head<=tail)
	{
		now=que[head++];
		for (int k=0; k<4; k++)
		{
			tmp.x=now.x+dx[k];
			tmp.y=now.y+dy[k];
			if (tmp.x<1||tmp.x>N||tmp.y<1||tmp.y>N) continue;
			if (vis[tmp.x][tmp.y]||abs(grid[tmp.x][tmp.y]-grid[now.x][now.y])>D) continue;
			vis[tmp.x][tmp.y]=true; res++;
			que[++tail]=tmp;
		}
	}
	return res;
}

bool solve(int D)
{
	memset(vis, 0, sizeof(vis));
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			if (!vis[i][j])
			{
				int tmp=calc_size(i, j, D);
				if (tmp>=M) return true;
			}
	return false;
}

int main()
{
	freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
			scanf("%d", &grid[i][j]);
	if (N&1) M=N*N/2+1;
	else M=N*N/2;
	int left=0, right=1000000;
	int ans=0;
	while (left<=right)
	{
		int mid=(left+right)>>1;
		if (solve(mid)) right=mid-1, ans=mid;
		else left=mid+1;
	}
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
