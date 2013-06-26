#include <cstdio>
#include <cstring>
#include <algorithm>

const int SIZE=35;
const int MAXN=205;
const int MAXM=20000;

typedef char str[SIZE];
typedef struct { int u, v, w; } node;

node edge[MAXM];
str name[MAXN];
int f[MAXN];
int n, m;
int s, t;

int get(str s)
{
	for (int i=1; i<=n; i++)
		if (!strcmp(s,name[i])) return i;
	strcpy(name[++n],s);
	return n;
}

bool cmp(node a, node b)
{
	return (a.w>b.w);
}

int find(int x)
{
	if (x!=f[x]) f[x]=find(f[x]);
	return f[x];
}

int main()
{
	int cas=0;
	while (scanf("%d%d", &n, &m)==2&&n)
	{
		int ret;
		str s1, s2;
		n=0;
		for (int i=0; i<m; i++)
		{
			scanf("%s%s%d", s1, s2, &edge[i].w);
			edge[i].u=get(s1);
			edge[i].v=get(s2);
		}
		scanf("%s%s", s1, s2);
		s=get(s1); t=get(s2);
		std::sort(edge,edge+m,cmp);
		for (int i=0; i<=n; i++) f[i]=i;
		for (int i=0; i<m; i++)
		{
			int u=find(edge[i].u);
			int v=find(edge[i].v);
			if (u!=v) f[u]=v;
			if (find(s)==find(t)) 
			{
				ret=edge[i].w;
				break;
			}
		}
		printf("Scenario #%d\n%d tons\n\n", ++cas, ret);
	}
	return 0;
}
