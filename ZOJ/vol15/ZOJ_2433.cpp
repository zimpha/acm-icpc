#include <cstdio>

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		int n, ans, ret=2000000000;
		int pre, now;
		scanf("%d%d", &n, &pre);
		for (int i=2; i<n-1; i++)
		{
			scanf("%d", &now);
			int tmp=now-pre;
			if (tmp<ret)
			{
				ret=tmp;
				ans=i;
			}
			pre=now;
		}
		if (n>2) scanf("%d", &now);
		if (n>=4) printf("%d\n%d 1 %d %d\n", ret+now, ans+1, n, ans);
		else printf("0\n");
		if (test) puts("");
	}
	return 0;
}
