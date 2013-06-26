#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=205;
const int MAXM=40005;
const int inf=100000000;

struct node
{
	int cap, flow, lower;
};

struct EDGE
{
	int u, v;
};

node map[MAXN][MAXN];
EDGE e[MAXM];
int inflow[MAXN], outflow[MAXN];
int lev[MAXN], cur[MAXN];
int n, m, S, T;

void init()
{
	scanf("%d%d", &n, &m);
	memset(map, 0, sizeof(map));
	memset(inflow, 0, sizeof(inflow));
	memset(outflow, 0, sizeof(outflow));
	for (int i=1; i<=m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		scanf("%d%d", &map[u][v].lower, &map[u][v].cap);
		map[u][v].cap-=map[u][v].lower;
		e[i].u=u; e[i].v=v;
		inflow[v]+=map[u][v].lower;
		outflow[u]+=map[u][v].lower;
	}
}

void build()
{
	S=0; T=n+1;
	for (int i=1; i<=n; i++)
		if (inflow[i]>outflow[i]) map[S][i].cap=inflow[i]-outflow[i];
		else map[i][T].cap=outflow[i]-inflow[i];
}

bool dinic_bfs()
{
	queue<int>q;
	while (!q.empty()) q.pop();
	memset(lev, 0, sizeof(lev));
	lev[S]=1; q.push(S);
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		for (int v=S; v<=T; v++)
			if (!lev[v]&&map[u][v].cap>map[u][v].flow)
			{
				lev[v]=lev[u]+1;
				q.push(v);
			}
	}
	return (lev[T]>0);
}

int dinic_dfs(int u, int low)
{
	if (u==T) return low;
	for (int &v=cur[u]; v<=T; v++)
		if (lev[v]==lev[u]+1&&map[u][v].cap>map[u][v].flow)
		{
			int tmp=dinic_dfs(v, min(low, map[u][v].cap-map[u][v].flow));
			if (tmp)
			{
				map[u][v].flow+=tmp;
				map[v][u].flow-=tmp;
				return tmp;
			}
		}
	return 0;
}

void dinic()
{
	while (dinic_bfs())
	{
		memset(cur, 0, sizeof(cur));
		while (1)
		{
			int tmp=dinic_dfs(S, inf);
			if (!tmp) break;
		}
	}
}

void print()
{
	bool flag=true;
	for (int i=1; i<=n; i++)
		if (map[S][i].cap!=map[S][i].flow) flag=false;
	if (flag)
	{
		printf("YES\n");
		for (int i=1; i<=m; i++)
			printf("%d\n", map[e[i].u][e[i].v].lower+map[e[i].u][e[i].v].flow);
	}
	else printf("NO\n");
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		init();
		build();
		dinic();
		print();
		if (test) puts("");
	}
	return 0;
}
