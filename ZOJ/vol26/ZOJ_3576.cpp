#include <cmath>
#include <cstdio>
#include <cstring>

typedef long long LL;

LL gcd(LL a, LL b)
{
	if (b==0) return a;
	else return gcd(b, a%b);
}

int main()
{
	LL n, m;
	double ans;
	while (scanf("%lld%lld", &n, &m)==2)
	{
		if ((n&1)&&(m&1))
		{
			LL times=gcd(n, m);
			n/=times; m/=times;
			ans=(double)times*sqrt((double)n*n+m*m)*(n*m+1.0)/(2*n*m);
		}
		else ans=(double)sqrt((double)n*n+m*m)/2.0;
		printf("%.3f\n", ans);
	}
	return 0;
}
