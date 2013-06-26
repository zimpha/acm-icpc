#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXM=15005;
const int MAXN=1005;

struct node
{
	int u, v, w;
};

node edge[MAXM];
int ret[MAXN];
int f[MAXN];
int n, m;

bool cmp(node a, node b)
{
	return (a.w<b.w);
}

int find(int x)
{
	if (x!=f[x]) f[x]=find(f[x]);
	return f[x];
}

int main()
{
	while (scanf("%d%d", &n, &m)==2)
	{
	for (int i=0; i<m; i++)
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	std::sort(edge,edge+m,cmp);
	int count=0;
	for (int i=0; i<MAXN; i++)
		f[i]=i;
	for (int i=0; i<m; i++)
	{
		int u=find(edge[i].u);
		int v=find(edge[i].v);
		if (u!=v)
		{
			f[u]=v;
			ret[count++]=i;
			if (count==n-1)
			{
				printf("%d\n%d\n", edge[i].w, count);
				break;
			}
		}
	}
	for (int i=0; i<count; i++)
		printf("%d %d\n", edge[ret[i]].u, edge[ret[i]].v);
	}
	return 0;
}
