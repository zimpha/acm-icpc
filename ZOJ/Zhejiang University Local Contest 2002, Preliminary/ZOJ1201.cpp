#include <cstdio>
#include <cstring>

const int MAXN=55;

int a[MAXN], b[MAXN];
int n;

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		getchar();
		char cmd=getchar();
		for (int i=1; i<=n; i++)
			scanf("%d", &a[i]);
		if (cmd=='P')
		{
			memset(b,0,sizeof(b));
			for (int i=1; i<=n; i++)
				for (int j=i+1; j<=n; j++)
					if (a[i]>a[j]) b[a[j]]++;
		}
		else
		{
			memset(b,0,sizeof(b));
			for (int i=1; i<=n; i++)
			{
				int pos, count;
				for (pos=1, count=0; count<a[i]; pos++)
					if (!b[pos]) count++;
				while (b[pos]) pos++;
				b[pos]=i;
			}
		}
		for (int i=1; i<=n; i++)
			printf("%d%c", b[i], (i<n)?' ':'\n');
	}
	return 0;
}
