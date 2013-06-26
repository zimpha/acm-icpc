#include <cstdio>
#include <cstring>

int ans[100];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		int m=0, p=0;
		while (n)
		{
			if (n&1) ans[m++]=p;
			p++; n>>=1;
		}
		for (int i=0; i<m; i++)
			printf("%d%c", ans[i], (i==m-1)?'\n':' ');
	}
	return 0;
}
