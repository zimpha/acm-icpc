#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int dx[]={1, -1, -1, 1};
const int dy[]={1, 1, -1, -1};
const int tx[]={1, 1, -1, -1};
const int ty[]={-1, 1, 1, -1};
const int MAXN=55;

struct node
{
	char c;
	int len, t;
};

struct node1
{
	int x, y, d, s;
};

bool vis[MAXN][MAXN][4];
bool map[MAXN][MAXN];
bool used[MAXN];
node blk[MAXN];
int x[MAXN];
int y[MAXN];
int N, M, B;
int ret;

inline int check0(int x, int y)
{
	if (map[x+1][y]==0&&map[x+1][y+1]==0&&map[x][y+1]==0) return 0;
	if (map[x+1][y]==1&&map[x+1][y+1]==0&&map[x][y+1]==0) return 1;
	if (map[x+1][y]==1&&map[x+1][y+1]==1&&map[x][y+1]==0) return 1;
	if (map[x+1][y]==1&&map[x+1][y+1]==0&&map[x][y+1]==1) return 2;
	if (map[x+1][y]==0&&map[x+1][y+1]==1&&map[x][y+1]==0) return 2;
	if (map[x+1][y]==1&&map[x+1][y+1]==1&&map[x][y+1]==1) return 2;
	if (map[x+1][y]==0&&map[x+1][y+1]==0&&map[x][y+1]==1) return 3;
	if (map[x+1][y]==0&&map[x+1][y+1]==1&&map[x][y+1]==1) return 3;
}

inline int check1(int x, int y)
{
	if (map[x-1][y]==0&&map[x-1][y+1]==0&&map[x][y+1]==0) return 0;
	if (map[x-1][y]==0&&map[x-1][y+1]==0&&map[x][y+1]==1) return 1;
	if (map[x-1][y]==0&&map[x-1][y+1]==1&&map[x][y+1]==1) return 1;
	if (map[x-1][y]==0&&map[x-1][y+1]==1&&map[x][y+1]==0) return 2;
	if (map[x-1][y]==1&&map[x-1][y+1]==0&&map[x][y+1]==1) return 2;
	if (map[x-1][y]==1&&map[x-1][y+1]==1&&map[x][y+1]==1) return 2;
	if (map[x-1][y]==1&&map[x-1][y+1]==0&&map[x][y+1]==0) return 3;
	if (map[x-1][y]==1&&map[x-1][y+1]==1&&map[x][y+1]==0) return 3;
}

inline int check2(int x, int y)
{
	if (map[x-1][y]==0&&map[x-1][y-1]==0&&map[x][y-1]==0) return 0;
	if (map[x-1][y]==1&&map[x-1][y-1]==0&&map[x][y-1]==0) return 1;
	if (map[x-1][y]==1&&map[x-1][y-1]==1&&map[x][y-1]==0) return 1;
	if (map[x-1][y]==0&&map[x-1][y-1]==1&&map[x][y-1]==0) return 2;
	if (map[x-1][y]==1&&map[x-1][y-1]==0&&map[x][y-1]==1) return 2;
	if (map[x-1][y]==1&&map[x-1][y-1]==1&&map[x][y-1]==1) return 2;
	if (map[x-1][y]==0&&map[x-1][y-1]==0&&map[x][y-1]==1) return 3;
	if (map[x-1][y]==0&&map[x-1][y-1]==1&&map[x][y-1]==1) return 3;
}

inline int check3(int x, int y)
{
	if (map[x+1][y]==0&&map[x+1][y-1]==0&&map[x][y-1]==0) return 0;
	if (map[x+1][y]==0&&map[x+1][y-1]==0&&map[x][y-1]==1) return 1;
	if (map[x+1][y]==0&&map[x+1][y-1]==1&&map[x][y-1]==1) return 1;
	if (map[x+1][y]==0&&map[x+1][y-1]==1&&map[x][y-1]==0) return 2;
	if (map[x+1][y]==1&&map[x+1][y-1]==0&&map[x][y-1]==1) return 2;
	if (map[x+1][y]==1&&map[x+1][y-1]==1&&map[x][y-1]==1) return 2;
	if (map[x+1][y]==1&&map[x+1][y-1]==1&&map[x][y-1]==0) return 3;
	if (map[x+1][y]==1&&map[x+1][y-1]==0&&map[x][y-1]==0) return 3;
}

bool bfs()
{
	queue<node1> q;
	while (!q.empty()) q.pop();
	memset(vis, 0, sizeof(vis));
	vis[1][1][0]=1;
	q.push((node1){1, 1, 0, 0});
	while (!q.empty())
	{
		node1 now=q.front(); q.pop();
		node1 tmp=now; tmp.s++;
		int t;
		if (now.x==1&&now.y==1&&now.s!=0) return true;
		switch (now.d)
		{
		case 0:
			t=check0(now.x, now.y);
			if (t==0) tmp.x+=dx[tmp.d], tmp.y+=dy[tmp.d];
			else tmp.d=(tmp.d+t)%4;
			if (!vis[tmp.x][tmp.y][tmp.d])
			{
				vis[tmp.x][tmp.y][tmp.d]=1;
				q.push(tmp);
			}
			break;
		case 1:
			t=check1(now.x, now.y);
			if (t==0) tmp.x+=dx[tmp.d], tmp.y+=dy[tmp.d];
			else tmp.d=(tmp.d+t)%4;
			if (!vis[tmp.x][tmp.y][tmp.d])
			{
				vis[tmp.x][tmp.y][tmp.d]=1;
				q.push(tmp);
			}
			break;
		case 2:
			t=check2(now.x, now.y);
			if (t==0) tmp.x+=dx[tmp.d], tmp.y+=dy[tmp.d];
			else tmp.d=(tmp.d+t)%4;
			if (!vis[tmp.x][tmp.y][tmp.d])
			{
				vis[tmp.x][tmp.y][tmp.d]=1;
				q.push(tmp);
			}
			break;
		case 3:
			t=check3(now.x, now.y);
			if (t==0) tmp.x+=dx[tmp.d], tmp.y+=dy[tmp.d];
			else tmp.d=(tmp.d+t)%4;
			if (!vis[tmp.x][tmp.y][tmp.d])
			{
				vis[tmp.x][tmp.y][tmp.d]=1;
				q.push(tmp);
			}
			break;
		}
	}
	return false;
}

inline void fillS(int x, int y, int len)
{
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
			map[x-i][y+j]=1;
}

inline void unfillS(int x, int y, int len)
{
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
			map[x-i][y+j]=0;
}

inline bool canfillS(int x, int y, int len)
{
	for (int i=0; i<len; i++)
		for (int j=0; j<len; j++)
		{
			int xx=x-i, yy=y+j;
			if (xx<1||xx>N||yy<1||yy>M) return false;
			if (map[xx][yy]||(xx==2&&yy==2)||(xx==1&&yy==2)||(xx==2&&yy==1)) return false;
		}
	return true;
}

inline void fillT(int x, int y, int len, int t)
{
	int dx=tx[t-1], dy=ty[t-1];
	for (int i=0; i<len; i++)
		for (int j=0; j<len-i; j++)
			map[x+i*dx][y+j*dy]=1;	
}

inline void unfillT(int x, int y, int len, int t)
{
	int dx=tx[t-1], dy=ty[t-1];
	for (int i=0; i<len; i++)
		for (int j=0; j<len-i; j++)
			map[x+i*dx][y+j*dy]=0;	
}

inline bool canfillT(int x, int y, int len, int t)
{
	int dx=tx[t-1], dy=ty[t-1];
	for (int i=0; i<len; i++)
		for (int j=0; j<len-i; j++)
		{
			int xx=x+i*dx, yy=y+j*dy;
			if (xx<1||xx>N||yy<1||yy>M) return false;
			if (map[xx][yy]||(xx==2&&yy==2)||(xx==1&&yy==2)||(xx==2&&yy==1)) return false;
		}
	return true;
}

void dfs(int cur)
{
	if (cur==B)
	{
		if (bfs()) ret++;
		return;
	}
	for (int i=0; i<B; i++)
	{
		if (used[i]) continue;
		used[i]=true;
		if (blk[i].c=='S')
		{
			if (canfillS(x[cur], y[cur], blk[i].len))
			{
				fillS(x[cur], y[cur], blk[i].len);
				dfs(cur+1);
				unfillS(x[cur], y[cur], blk[i].len);
			}
		}
		else
		{
			if (canfillT(x[cur], y[cur], blk[i].len, blk[i].t))
			{
				fillT(x[cur], y[cur], blk[i].len, blk[i].t);
				dfs(cur+1);
				unfillT(x[cur], y[cur], blk[i].len, blk[i].t);
			}
		}
		used[i]=false;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &M, &N, &B);
		for (int i=0; i<B; i++)
		{
			char st[10];
			scanf("%s%d", st, &blk[i].len);
			blk[i].c=st[0];
			if (st[0]=='T') scanf("%d", &blk[i].t);
		}
		for (int i=0; i<B; i++) scanf("%d%d", &y[i], &x[i]);
		for (int i=0; i<=N+1; i++)
			for (int j=0; j<=M+1; j++)
				if (i==0||j==0||i==N+1||j==M+1) map[i][j]=1;
				else map[i][j]=0;
		memset(used, 0, sizeof(used));
		ret=0;
		dfs(0);
		printf("%d\n", ret);
	}
	return 0;
}
