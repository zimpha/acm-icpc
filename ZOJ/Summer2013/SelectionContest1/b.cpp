#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN=1010;
const int MAXM=1010;
const int inf=100000000;

struct  node
{
	int v, w;
	int next;
}edge[MAXM], edge1[MAXM];

int head[MAXN], head1[MAXN], hash[MAXN];
int path[MAXN][MAXN], path1[MAXN][MAXN];
int g[MAXN][MAXN], g1[MAXN][MAXN];
int n,m,k,cnt,cnt1;
int prt[MAXN],prt1[MAXN];

void addedge(int u,int v,int w)
{
	edge[cnt].v=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt++;
}

void addedge1(int u,int v,int w)
{
	edge1[cnt1].v=v; edge1[cnt1].w=w; edge1[cnt1].next=head1[u]; head1[u]=cnt1++;
}

void spfa(int s)
{
	queue<int>que;
	for(int i=1; i<=n; i++)
	{
		g[s][i]=-inf;
		path[s][i]=-1;
	}
	memset(hash, 0, sizeof(hash));
	while (!que.empty()) que.pop();
	que.push(s); g[s][s]=0; path[s][s]=-1; hash[s]=1;
	while (!que.empty())
	{
		int u=que.front(); que.pop();
		hash[u]=0;
		for (int p=head[u]; p!=-1; p=edge[p].next)
		{
			int v=edge[p].v;
			if(g[s][v]<g[s][u]+edge[p].w)
			{
				path[s][v]=u;
				g[s][v]=g[s][u]+edge[p].w;
				if (!hash[v])
				{
					hash[v]=1;
					que.push(v);
				}
			}
		}
	}
}

void spfa1(int s)
{
	queue<int>que;
	for(int i=1; i<=n; i++)
	{
		g1[s][i]=inf;
		path1[s][i]=-1;
	}
	memset(hash, 0, sizeof(hash));
	while (!que.empty()) que.pop();
	que.push(s); g1[s][s]=0; hash[s]=1; path1[s][s]=-1;
	while (!que.empty())
	{
		int u=que.front(); que.pop();
		hash[u]=0;
		for (int p=head1[u]; p!=-1; p=edge1[p].next)
		{
			int v=edge1[p].v;
			if(g1[s][v]>g1[s][u]+edge1[p].w)
			{
				path1[s][v]=u;
				g1[s][v]=g1[s][u]+edge1[p].w;
				if(!hash[v])
				{
					hash[v]=1;
					que.push(v);
				}
			}
		}
	}
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		cnt=0; cnt1=0;
		memset(head,-1,sizeof(head)); memset(head1,-1,sizeof(head1));
		memset(path,-1,sizeof(path)); memset(path1,-1,sizeof(path1));
		memset(g,0,sizeof(g)); memset(g1,0,sizeof(g1));
		scanf("%d%d%d", &n, &m, &k);
		for(int i=0; i<m; i++)
		{
			int x,y,key;
			scanf("%d%d%d", &x, &y, &key);
			addedge(x, y, key);
		}
		for(int i=0; i<k; i++)
		{
			int x, y, key;
			scanf("%d%d%d", &x, &y, &key);
			addedge1(x, y, key);
		}
		for(int i=1; i<=n; i++)
		{
			spfa(i);
			spfa1(i);
		}
		int ku, kv, d;
		double ret=-1;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				if (g[i][j]!=-inf&&g1[j][i]!=inf)
					if((double)g[i][j]/(double)g1[j][i]>ret)
					{
						ret=(double)g[i][j]/(double)g1[j][i];
						ku=i; kv=j;
					}
			}
		int i=ku, j=kv;
		d=ku; cnt1=0;
		while (d!=-1)
		{
			prt1[cnt1++]=d;
			d=path1[j][d];
		}
		for (int i=cnt1-1; i>=0; i--)
			printf("%d ",prt1[i]);
		d=kv; cnt=0;
		while(d!=-1)
		{
			prt[cnt++]=d;
			d=path[i][d];
		}
		for(int i=cnt-2; i>=0; i--)
			printf("%d%c", prt[i], (i==0)?'\n':' ');
		printf("%.3lf\n", ret);
	}
	return 0;
}
