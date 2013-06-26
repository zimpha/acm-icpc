#include <queue>
#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using std::queue;

const int MAXN=55;
const int inf=INT_MAX>>2;

struct node
{
	int a, b;
};

queue<node>q;
node dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
int tele[MAXN][MAXN];
int enter[MAXN];
int Exit[MAXN];
int cell[MAXN];
int n, price;

void spfa()
{
	while (!q.empty()) q.pop();
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
		{
			dis[i][j].a=dis[i][j].b=inf;
			vis[i][j]=false;
		}
	vis[0][0]=true;
	dis[0][0].a=dis[0][0].b=0;
	node now;
	now.a=now.b=0;
	q.push(now);
	while (!q.empty())
	{
		now=q.front(); q.pop();
		// go forward
		if ((now.a+1<n)&&cell[now.a+1]!=-1)
		{
			node tmp=now;
			tmp.a++;
			if (tmp.b<=n)
			{
				if (dis[tmp.a][tmp.b].a>dis[now.a][now.b].a+cell[tmp.a])
				{
					dis[tmp.a][tmp.b].a=dis[now.a][now.b].a+cell[tmp.a];
					dis[tmp.a][tmp.b].b=dis[now.a][now.b].b+1;
					if (!vis[tmp.a][tmp.b])
					{
						vis[tmp.a][tmp.b]=true;
						q.push(tmp);
					}
				}
				else if (dis[tmp.a][tmp.b].a==dis[now.a][now.b].a+cell[tmp.a])
				{
					if (dis[tmp.a][tmp.b].b>dis[now.a][now.b].b+1)
					{
						dis[tmp.a][tmp.b].b=dis[now.a][now.b].b+1;
						if (!vis[tmp.a][tmp.b])
						{
							vis[tmp.a][tmp.b]=true;
							q.push(tmp);
						}
					}
				}
			}
		}
		// go back
		if ((now.a>1)&&cell[now.a-1]!=-1)
		{
			node tmp=now;
			tmp.a--;
			if (tmp.b<=n)
			{
				if (dis[tmp.a][tmp.b].a>dis[now.a][now.b].a+cell[tmp.a])
				{
					dis[tmp.a][tmp.b].a=dis[now.a][now.b].a+cell[tmp.a];
					dis[tmp.a][tmp.b].b=dis[now.a][now.b].b+1;
					if (!vis[tmp.a][tmp.b])
					{
						vis[tmp.a][tmp.b]=true;
						q.push(tmp);
					}
				}
				else if (dis[tmp.a][tmp.b].a==dis[now.a][now.b].a+cell[tmp.a])
				{
					if (dis[tmp.a][tmp.b].b>dis[now.a][now.b].b+1)
					{
						dis[tmp.a][tmp.b].b=dis[now.a][now.b].b+1;
						if (!vis[tmp.a][tmp.b])
						{
							vis[tmp.a][tmp.b]=true;
							q.push(tmp);
						}
					}
				}
			}
		}
		// use teleports
		for (int i=1; i<=tele[now.a][0]; i++)
		{
			node tmp;
			tmp.a=tele[now.a][i];
			tmp.b=now.b+1;
			if (cell[tmp.a]!=-1&&tmp.b<=n)
			{
				if (dis[tmp.a][tmp.b].a>dis[now.a][now.b].a+price+now.b)
				{
					dis[tmp.a][tmp.b].a=dis[now.a][now.b].a+price+now.b;
					dis[tmp.a][tmp.b].b=dis[now.a][now.b].b+1;
					if (!vis[tmp.a][tmp.b])
					{
						vis[tmp.a][tmp.b]=true;
						q.push(tmp);
					}
				}
				else if (dis[tmp.a][tmp.b].a==dis[now.a][now.b].a+price+now.b)
				{
					if (dis[tmp.a][tmp.b].b>dis[now.a][now.b].b+1)
					{
						dis[tmp.a][tmp.b].b=dis[now.a][now.b].b+1;
						if (!vis[tmp.a][tmp.b])
						{
							vis[tmp.a][tmp.b]=true;
							q.push(tmp);
						}
					}
				}
			}
		}
		vis[now.a][now.b]=false;
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d", cell+i);
		int m;
		scanf("%d", &m);
		for (int i=1; i<=m; i++)
			scanf("%d", enter+i);
		scanf("%d", &m);
		for (int i=1; i<=m; i++)
			scanf("%d", Exit+i);
		scanf("%d", &price);
		memset(tele,0,sizeof(tele));
		for (int i=1; i<=m; i++)
		{
			tele[enter[i]][0]++;
			tele[enter[i]][tele[enter[i]][0]]=Exit[i];
		}
		spfa();
		node ans;
		ans.a=inf;
		for (int i=0; i<=n; i++)
			if (dis[n-1][i].a<ans.a) ans=dis[n-1][i];
			else if (dis[n-1][i].a==ans.a)
			{
				if (dis[n-1][i].b<ans.b) ans=dis[n-1][i];
			}
		if (ans.a<inf) printf("%d %d\n", ans.a, ans.b);
		else puts("");
	}
	return 0;
}
