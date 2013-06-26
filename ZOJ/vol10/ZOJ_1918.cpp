#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1500;
const int inf=100000000;

int f[MAXN], g[MAXN];
int a[MAXN];
int n, t, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d%d", &n, &t, &m);
		memset(f,0,sizeof(f));
		memset(f,0,sizeof(g));
		for (int i=1; i<=m; i++)
		{
			scanf("%d", a+i);
			f[i]=g[i]=inf;
			for (int j=i-n; j<i; j++)
			{
				int tmp=std::max(f[j],a[i])+2*t;
				if (tmp<=f[i])
				{
					f[i]=tmp;
					if (tmp==f[i]) g[i]=std::min(g[i],g[j]+1);
				}
			}
		}
		printf("%d %d\n", f[m]-t, g[m]);
	}
	return 0;
}
