#include <cstdio>

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		int n, sum=0;
		scanf("%d", &n);
		while (n)
		{
			if (n&1) sum++;
			n>>=1;
		}
		printf("%d\n", sum);
	}
	return 0;
}
