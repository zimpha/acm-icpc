#include <cstdio>

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
	int n;
	while (scanf("%d", &n)==1&&n)
	{
		int day, ret, cost;
		ret=0; day=n; cost=0;
		while (1)
		{
			if (day-cost<=0) 
			{
				ret+=day*cost;
				break;
			}
			else ret+=cost*cost;
			day-=cost;
			cost++;
		}
		printf("%d %d\n", n, ret);
	}
	if (test) puts("");
	}
	return 0;
}
