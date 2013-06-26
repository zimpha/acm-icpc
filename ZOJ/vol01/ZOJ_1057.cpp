#include <cstdio>
#include <cstring>

const int MAXN=25;

int a[MAXN], b[MAXN];
int n;

int main()
{
	int cas=0;
	while (scanf("%d", &n)==1&&n)
	{
		if (cas++) puts("");
		int sa=0, sb=0;
		for (int i=0; i<n; i++)
			scanf("%d", &a[i]);
		for (int i=0; i<n; i++)
			scanf("%d", &b[i]);
		for (int i=0; i<n; i++)
		{
			if (a[i]+1==b[i])
			{
				sa+=a[i]+b[i];
				if (a[i]==1) sa+=3;
			}
			if (a[i]+1<b[i]) sb+=b[i];
			if (a[i]==b[i]+1)
			{
				sb+=a[i]+b[i];
				if (b[i]==1) sb+=3;
			}
			if (a[i]>b[i]+1) sa+=a[i];
		}
		printf("A has %d points. B has %d points.\n", sa, sb);
	}
	return 0;
}
