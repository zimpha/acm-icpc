#include <cstdio>
#include <cstring>

int main()
{
	long long n, k;
	while (scanf("%lld%lld", &n, &k)==2&&n)
	{	
		long long ret=1;
		if (n-k>k) k=n-k;
		int num=n-k;
		for (int i=n; i>=k+1; i--)
		{
			ret*=i;
			if (num>=1&&ret%num==0)
			{
				ret/=num;
				num--;
			}
		}
		for (int i=1; i<=num; i++) ret/=i;
		printf("%lld\n", ret);
	}
	return 0;
}
