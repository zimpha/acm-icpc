#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=40005;

int a[MAXN];
int f[MAXN];
int n;

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
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", a+i);
		int cnt=0; f[0]=0;
		for (int i=1; i<=n; i++)
		{
			int tmp=find(1,cnt,a[i]);
			f[tmp]=a[i];
			if (tmp>cnt) cnt=tmp;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
