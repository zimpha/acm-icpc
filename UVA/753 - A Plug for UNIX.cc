#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>

const int MAXN=505;
const int MAXM=1005;
const int inf=100000000;

struct node
{
    int v,c,f;
    int next;
};

std::string s[MAXN],st[MAXN];
node e[MAXM];
int head[MAXN],work[MAXN];
int level[MAXN];
int n,m,k,cnt;
int S,T;

void addedge(int u,int v,int c)
{
    e[cnt].v=v; e[cnt].c=c; e[cnt].f=0; e[cnt].next=head[u]; head[u]=cnt++;
    e[cnt].v=u; e[cnt].c=0; e[cnt].f=0; e[cnt].next=head[v]; head[v]=cnt++;
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
	for (int now=head[u]; now!=-1; now=e[now].next)
	{
	    int v=e[now].v;
	    if (!level[v]&&e[now].c>e[now].f)
	    {
		level[v]=level[u]+1;
		q.push(v);
	    }
	}
    }
    return (level[T]>0);
}

int dinic_dfs(int u,int low)
{
    if (u==T) return low;
    for (int &now=work[u]; now!=-1; now=e[now].next)
    {
	int v=e[now].v;
	if (level[v]==level[u]+1&&e[now].c>e[now].f)
	{
	    int tmp=dinic_dfs(v,std::min(low,e[now].c-e[now].f));
	    if (tmp>0)
	    {
		e[now].f+=tmp;
		e[now^1].f-=tmp;
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
	memcpy(work,head,sizeof(head));
	while (1)
	{
	    int tmp=dinic_dfs(S,inf);
	    if (tmp==0) break;
	    maxflow+=tmp;
	}
    }
    return maxflow;
}

int find(std::string a)
{
    for (int i=1; i<=T; i++)
	if (a==s[i]) return i;
    s[++T]=a; return T;
}

int main()
{
	int test;
	scanf("%d",&test);
    while (test--)
    {
    	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	    std::cin>>s[i];
	std::string s1,s2;
	scanf("%d",&m);
	T=n; S=cnt=0;
	memset(head,-1,sizeof(head));
	for (int i=1; i<=n; i++) addedge(S,i,1);
	for (int i=1; i<=m; i++)
	{
	    std::cin>>st[i]>>s2;
	    int v=find(st[i]), u=find(s2);
	    addedge(u,v,1);
	}
	scanf("%d",&k);
	for (int i=1; i<=k; i++)
	{
	    std::cin>>s1>>s2;
	    int v=find(s1), u=find(s2);
	    addedge(u,v,inf);
	}
	T++;
	for (int i=1; i<=m; i++)
	{
	    int u=find(st[i]);
	    addedge(u,T,1);
	}
	int maxflow=dinic();
	printf("%d\n",m-maxflow);
	if (test) printf("\n");
    }
    return 0;
}
