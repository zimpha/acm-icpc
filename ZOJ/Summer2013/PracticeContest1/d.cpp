#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=55;

int raw[MAXN];
int n;

int main()
{
	int test;
	scanf("%d\n", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", raw+i);
		scanf("%d", &n);
		int sum=0;
		for (int i=1; i<=n; i++)
		{
			double con;
			scanf("%lf", &con);
			sum+=floor((double)raw[i]/con+0.5);
		}
		printf("%d\n", sum);
	}
	return 0;
}
