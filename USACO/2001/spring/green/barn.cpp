#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=1000;
const int MAXM=50005;
const int inf=100000000;

struct node
{
	int v, cap, flow;
	node *ne, *op;
};

node *head[MAXN], *work[MAXN];
int lev[MAXN];
int n, m;
int S, T;

void addedge(int u, int v, int cap)
{
	node *pu=new(node), *pv=new(node);
	pu->v=v; pu->cap=cap; pu->flow=0; pu->ne=head[u];
	pv->v=u; pv->cap=0; pv->flow=0; pv->ne=head[v];
	head[u]=pu; head[u]->op=pv;
	head[v]=pv; head[v]->op=pu;
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
		for (node *p=head[u]; p; p=p->ne)
			if (!lev[p->v]&&p->cap>p->flow)
			{
				lev[p->v]=lev[u]+1;
				q.push(p->v);
			}
	}
	return (lev[T]>0);
}

int dinic_dfs(int u, int low)
{
	if (u==T) return low;
	for (node *p=work[u]; p; p=p->ne)
	{
		int v=p->v; work[u]=p;
		if (lev[v]==lev[u]+1&&p->cap>p->flow)
		{
			int tmp=dinic_dfs(v, min(low, p->cap-p->flow));
			if (tmp)
			{
				p->flow+=tmp;
				p->op->flow-=tmp;
				return tmp;
			}
		}
	}
	return 0;
}

int dinic()
{
	int maxflow=0;
	while (dinic_bfs())
	{
		memcpy(work, head, sizeof(head));
		while (1)
		{
			int tmp=dinic_dfs(S, inf);
			if (!tmp) break;
			maxflow+=tmp;
		}
	}
	return maxflow;
}

int main()
{
	freopen("barn.in", "r", stdin);
	freopen("barn.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(head, 0, sizeof(head));
	for (int i=0; i<m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u+n, v, inf);
		addedge(v+n, u, inf);
	}
	for (int i=3; i<=n; i++)
		addedge(i, i+n, 1);
	addedge(1, 1+n, inf); addedge(2, 2+n, inf);
	S=1; T=n+2;
	printf("%d\n", dinic());
	fclose(stdin); fclose(stdout);
	return 0;
}
