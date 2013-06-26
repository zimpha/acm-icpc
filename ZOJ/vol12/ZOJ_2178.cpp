#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN=20005;

int f[MAXN], v[MAXN];
int n;

int find(int x)
{
	if (x!=f[x])
	{
		int tmp=f[x];
		f[x]=find(f[x]);
		v[x]+=v[tmp];
	}
	return f[x];
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
		{
			f[i]=i; 
			v[i]=0;
		}
		while (1)
		{
			getchar();
			char ch=getchar();
			if (ch=='O') break;
			if (ch=='E') 
			{
				int x;
				scanf("%d", &x);
				find(x);
				printf("%d\n", v[x]);
			}
			else
			{
				int a, b;
				scanf("%d%d", &a, &b);
				f[a]=b; v[a]=abs(a-b)%1000;
			}
		}
	}
	return 0;
}
