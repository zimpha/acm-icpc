#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=105;
const int MAXM=405;
const int inf=1e9;
const double eps=1e-3;

struct node
{
	double cap, flow;
	int v;
	node *next, *op;
};

node *head[MAXN], *work[MAXN];
int u[MAXM], v[MAXM];
double w[MAXM];
int ans[MAXM];
int lev[MAXN];
int n, m;
int S, T;

void addedge(int u, int v, double cap)
{
	node *pu=new(node), *pv=new(node);
	pu->v=v; pu->cap=cap; pu->flow=0; pu->next=head[u];
	pv->v=u; pv->cap=0; pv->flow=0; pv->next=head[v];
	head[u]=pu; head[u]->op=pv;
	head[v]=pv; head[v]->op=pu;
}

bool dinic_bfs()
{
	queue<int>q;
	while (!q.empty()) q.pop();
	memset(lev, -1, sizeof(lev));
	lev[S]=1; q.push(S);
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		for (node *p=head[u]; p; p=p->next)
			if (lev[p->v]==-1&&p->cap>p->flow)
			{
				lev[p->v]=lev[u]+1;
				q.push(p->v);
			}
	}
	return (lev[T]>1);
}

double dinic_dfs(int u, double low)
{
	if (u==T) return low;
	for (node *p=work[u]; p; p=p->next)
	{
		int v=p->v; work[u]=p;
		if (lev[v]==lev[u]+1&&p->cap>p->flow)
		{
			double tmp=dinic_dfs(v, min(low, p->cap-p->flow));
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

double dinic()
{
	double maxflow=0;
	while (dinic_bfs())
	{
		memcpy(work, head, sizeof(head));
		while (1)
		{
			double tmp=dinic_dfs(S, inf);
			if (tmp<eps) break;
			maxflow+=tmp;
		}
	}
	return maxflow;
}

int main()
{
	int cas=0;
	while (scanf("%d%d", &n, &m)==2)
	{
		if (cas++) puts("");
		for (int i=1; i<=m; i++)
			scanf("%d%d%lf", &u[i], &v[i], &w[i]);
		double left=1, right=1e7;
		S=1; T=n;
		while (right-left>eps)
		{
			double mid=(left+right)/2;
			double ret=0;
			memset(head, 0, sizeof(head));
			for (int i=1; i<=m; i++)
				if (w[i]>mid) 
				{
					addedge(u[i], v[i], w[i]-mid);
					addedge(v[i], u[i], w[i]-mid);
				}
				else ret+=w[i]-mid;
			ret+=dinic();
			if (ret>0) left=mid;
			else right=mid;
		}
		ans[0]=0;
		for (int i=1; i<=m; i++)
			if (w[i]<=right||lev[u[i]]*lev[v[i]]<0)
				ans[++ans[0]]=i;
		printf("%d\n", ans[0]);
		for (int i=1; i<=ans[0]; i++)
			printf("%d%c", ans[i], (i==ans[0])?'\n':' ');
		if (!ans[0]) puts("");
	}
	return 0;
}
