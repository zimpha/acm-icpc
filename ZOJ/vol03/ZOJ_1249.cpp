#include <queue>
#include <cstdio>
#include <cstring>

const int MAXN=25;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
const char dire[9]={"EWSNewsn"};

struct node
{
	int px, py, bx, by;
	int step;
	bool operator<(const node a)const
	{
		return (step>a.step);
	}
};

bool vis[MAXN][MAXN][MAXN][MAXN];
node pre[MAXN][MAXN][MAXN][MAXN];
int dir[MAXN][MAXN][MAXN][MAXN];
int sx, sy, ex, ey, bx, by;
char map[MAXN][MAXN];
int n, m;
node ret;

void bfs()
{
	std::priority_queue<node>q;
	while (!q.empty()) q.pop();
	node st, ct;
	st.bx=bx; st.by=by;
	st.px=sx; st.py=sy;
	st.step=0; ret.step=-1;
	q.push(st);
	memset(vis,0,sizeof(vis));
	vis[bx][by][sx][sy]=1;
	while (!q.empty())
	{
		st=q.top(); q.pop();
		for (int i=0; i<4; i++)
		{
			ct.px=st.px+dx[i];
			ct.py=st.py+dy[i];
			if (ct.px>0&&ct.px<=n&&ct.py>0&&ct.py<=m&&map[ct.px][ct.py]!='#')
			{
				if (ct.px==st.bx&&ct.py==st.by)
				{
					int x=2*ct.px-st.px;
					int y=2*ct.py-st.py;
					if (x>0&&x<=n&&y>0&&y<=m&&map[x][y]!='#')
					{
						ct.bx=x; ct.by=y;
						if (vis[ct.bx][ct.by][ct.px][ct.py]) continue;
						vis[ct.bx][ct.by][ct.px][ct.py]=true;
						dir[ct.bx][ct.by][ct.px][ct.py]=i;
						pre[ct.bx][ct.by][ct.px][ct.py]=st;
						ct.step=st.step+4000;
						if (ct.bx==ex&&ct.by==ey)
						{
							ret=ct;
							return;
						}
						q.push(ct);
					}
				}
				else
				{
					ct.bx=st.bx; ct.by=st.by;
					if (vis[ct.bx][ct.by][ct.px][ct.py]) continue;
					vis[ct.bx][ct.by][ct.px][ct.py]=true;
					dir[ct.bx][ct.by][ct.px][ct.py]=i+4;
					pre[ct.bx][ct.by][ct.px][ct.py]=st;
					ct.step=st.step+1;
					q.push(ct);
				}
			}
		}
	}
}

void print(node tmp)
{
	if (tmp.bx==bx&&tmp.by==by&&tmp.px==sx&&tmp.py==sy) return;
	print(pre[tmp.bx][tmp.by][tmp.px][tmp.py]);
	putchar(dire[dir[tmp.bx][tmp.by][tmp.px][tmp.py]]);
}

int main()
{
	int cas=0;
	while (scanf("%d%d", &n, &m)==2&&n)
	{
		for (int i=1; i<=n; i++)
		{
			getchar();
			for (int j=1; j<=m; j++)
			{
				map[i][j]=getchar();
				if (map[i][j]=='S') sx=i, sy=j;
				if (map[i][j]=='T') ex=i, ey=j;
				if (map[i][j]=='B') bx=i, by=j;
			}
		}
		bfs();
		printf("Maze #%d\n", ++cas);
		if (ret.step==-1) printf("Impossible.\n\n");
		else
		{
			print(ret);
			printf("\n\n");
		}
	}
	return 0;
}
