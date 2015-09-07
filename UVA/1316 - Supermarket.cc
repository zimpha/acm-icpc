#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=10005;

struct node
{
	int p, d;
};

node task[MAXN];
int f[MAXN];
int n;

bool cmp(node a, node b)
{
	if (a.p==b.p) return (a.d<b.d);
	else return (a.p>b.p);
}

int find(int x)
{
	if (x!=f[x]) f[x]=find(f[x]);
	return f[x];
}

int main()
{
	while (scanf("%d", &n)==1)
	{
		for (int i=0; i<n; i++)
			scanf("%d%d", &task[i].p, &task[i].d);
		std::sort(task,task+n,cmp);
		for (int i=0; i<MAXN; i++) f[i]=i;
		int ret=0;
		for (int i=0; i<n; i++)
		{
			int tmp=find(task[i].d);
			if (tmp>0)
			{
				ret+=task[i].p;
				f[tmp]=tmp-1;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}

