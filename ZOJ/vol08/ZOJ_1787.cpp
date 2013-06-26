#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=10005;
const int inf=1000000;

struct node
{
	int l, m;
};

node block[MAXN];
int f[MAXN];
int n;

bool cmp(node a, node b)
{
	if (a.l==b.l) return (a.m<b.m);
	else return (a.l<b.l);
}

int find(int l, int r, int x)
{
	while (l<=r)
	{
		int m=(l+r)/2;
		if (f[m]>x) r=m-1;
		else l=m+1;
	}
	return l;
}

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=1; i<=n; i++)
			scanf("%d%d", &block[i].l, &block[i].m);
		std::sort(block+1,block+1+n,cmp);
		int cnt=0; f[0]=0;
		for (int i=1; i<=n; i++)
		{
			int tmp=find(1,cnt,block[i].m);
			f[tmp]=block[i].m;
			if (tmp>cnt) cnt=tmp;
		}
		printf("%d\n", cnt);
	}
	printf("*\n");
	return 0;
}
