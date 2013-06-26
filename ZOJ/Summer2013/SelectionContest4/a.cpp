#include <cstdio>
#include <cstring>

typedef long long LL;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		LL n, k, power, tmp;
		scanf("%lld%lld", &n, &k);
		tmp=n;
		power=1;
		while (tmp)
		{
			tmp/=10;
			power*=10;
		}
		tmp=0;
		int ans=-1;
		for (int i=1; i<=2*k; i++)
		{
			tmp=(tmp*power+n)%k;
			if (tmp==0)
			{
				ans=i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
