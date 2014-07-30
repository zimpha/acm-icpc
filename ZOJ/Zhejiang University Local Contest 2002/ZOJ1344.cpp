#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=55;
const int dx[]={-1, 0, 1, 0, 0};
const int dy[]={0, 1, 0, -1, 0};

struct node
{
	int x, y;
	int s;
};

queue<node> q;
node dog[MAXN];
bool vis[MAXN][MAXN][MAXN];
char map[MAXN][MAXN];
node st, ed;
int N, M, D;

bool check(node a)
{
	node b;
	if (a.s%D==0) b=dog[D];
	else b=dog[a.s%D];
	if (a.x==b.x&&a.y==b.y) return true;
	while (1)
	{
		b.x+=dx[b.s]; b.y+=dy[b.s];
		if (b.x<1||b.x>N||b.y<1||b.y>M) break;
		if (map[b.x][b.y]=='*') break;
		if (b.x==a.x&&b.y==a.y) return true;
	}
	return false;
}

void solve_dog()
{
	getchar(); dog[0].s=0;
	for (int i=1; i<=D; i++)
	{
		char c=getchar();
		switch (c)
		{
		case 'G':
			dog[i].x=dog[i-1].x+dx[dog[i-1].s];
			dog[i].y=dog[i-1].y+dy[dog[i-1].s];
			dog[i].s=dog[i-1].s;
			break;
		case 'L':
			dog[i]=dog[i-1];
			dog[i].s=(dog[i].s-1+4)%4;
			break;
		case 'R':
			dog[i]=dog[i-1];
			dog[i].s=(dog[i].s+1)%4;
			break;
		}
	}
}

void bfs(node st, node ed)
{
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) q.pop();
	st.s=0; q.push(st); vis[st.x][st.y][0]=1;
	while (!q.empty())
	{
		node now, tmp;
		now=q.front(); q.pop();
		if (now.x==ed.x&&now.y==ed.y)
		{
			printf("Minimal time is: %d\n", now.s);
			return;
		}
		for (int k=0; k<5; k++)
		{
			tmp.x=now.x+dx[k];
			tmp.y=now.y+dy[k];
			tmp.s=now.s+1;
			if (tmp.x<1||tmp.x>N||tmp.y<1||tmp.y>M) continue;
			if (map[tmp.x][tmp.y]=='*'||check(tmp)) continue;
			if (!vis[tmp.x][tmp.y][tmp.s%(D+1)])
			{
				vis[tmp.x][tmp.y][tmp.s%(D+1)]=1;
				q.push(tmp);
			}
		}
	}
	puts("No way out");
}

int main()
{
	int cas=0;
	while (scanf("%d%d", &N, &M)==2&&N)
	{
		scanf("%d%d%d%d", &st.x, &st.y, &ed.x, &ed.y);
		scanf("%d%d%d", &dog[0].x, &dog[0].y, &D);
		solve_dog();
		for (int i=1; i<=N; i++)
		{
			getchar();
			for (int j=1; j<=M; j++)
				map[i][j]=getchar();
		}
		if (cas) puts("");
		printf("Case %d:\n", ++cas);
		bfs(st, ed);
	}
	return 0;
}
