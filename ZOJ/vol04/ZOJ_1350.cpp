#include <cstdio>
#include <cstring>

const int MAXN=105;

int flag[MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		memset(flag,0,sizeof(flag));
		for (int i=1; i<=n; i++)
			for (int j=i; j<=n; j+=i)
				flag[j]^=1;
		int count=0;
		for (int i=1; i<=n; i++)
			if (flag[i]) count++;
		printf("%d\n", count);
	}
	return 0;
}
