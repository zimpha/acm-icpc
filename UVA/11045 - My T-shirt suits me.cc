#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::string;

const int MAXN=40;
const int inf=100000;

int cap[MAXN][MAXN],flow[MAXN][MAXN];
int level[MAXN];
int n,m,S,T;

int get(string s)
{
    if (s=="XXL") return 1;
    if (s=="XL") return 2;
    if (s=="L") return 3;
    if (s=="M") return 4;
    if (s=="S") return 5;
    return 6;
}

bool dinic_bfs()
{
    std::queue<int>q;
    while (!q.empty()) q.pop();
    memset(level,0,sizeof(level));
    q.push(S); level[S]=1;
    while (!q.empty())
    {
	int u=q.front(); q.pop();
	for (int v=0; v<=T; v++)
	    if (cap[u][v]>flow[u][v]&&!level[v])
	    {
		level[v]=level[u]+1;
		q.push(v);
	    }
    }
    return (level[T]>0);
}

int dinic_dfs(int u,int low)
{
    if (u==T) return low;
    for (int v=0; v<=T; v++)
	if (level[v]==level[u]+1&&cap[u][v]>flow[u][v])
	{
	    int tmp=dinic_dfs(v,std::min(low,cap[u][v]-flow[u][v]));
	    if (tmp>0)
	    {
		flow[u][v]+=tmp;
		flow[v][u]-=tmp;
		return tmp;
	    }
	}
    return 0;
}

int dinic()
{
    int maxflow=0;
    while (dinic_bfs())
    {
	while (1)
	{
	    int tmp=dinic_dfs(S,inf);
	    if (tmp==0) break;
	    maxflow+=tmp;
	}
    }
    return maxflow;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d%d",&n,&m);
	S=0; T=m+6+1;
	memset(flow,0,sizeof(flow));
	memset(cap,0,sizeof(cap));
	for (int i=1; i<=6; i++) cap[S][i]=n/6;
	for (int i=1; i<=m; i++)
	{
	    cap[i+6][T]=1;
	    string s;
	    int u;
	    std::cin>>s; u=get(s); cap[u][i+6]=1;
	    std::cin>>s; u=get(s); cap[u][i+6]=1;
	}
	int maxflow=dinic();
	if (maxflow==m) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
