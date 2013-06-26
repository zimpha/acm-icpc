#include <cmath>
#include <cstdio>
#include <cstring>

typedef long long LL;

LL n;

bool check(LL n)
{
	for (int i=2; i*i<=n; i++)
		if (n%i==0) return false;
	return true;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%lld", &n);
		LL ans1=0, ans2=0;
		for (int q=2; q<60; q++)
		{
			LL p=floor(pow(n, 1.0/q)+0.5);
			if (!check(p)) continue;
			LL tmp=1;
			for (int i=0; i<q; i++)
				tmp*=p;
			if (tmp==n)
			{
				ans1=p; ans2=q;
				break;
			}
		}
		if (ans2) printf("%lld %lld\n", ans1, ans2);
		else puts("");
	}
	return 0;
}
