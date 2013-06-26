#include <cstdio>
#include <cstring>

int main()
{
	int n, o, p;
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		p=0;
		while (n%2==0)
		{
			p++;
			n/=2;
		}
		printf("%d %d\n", n, p);
	}
	return 0;
}
