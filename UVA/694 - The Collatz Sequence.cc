#include <cstdio>

int main()
{
	long long a,limit;
	int count,test=0;
	while (scanf("%lld%lld",&a,&limit)&&a!=-1)
	{
		printf("Case %d: A = %lld, limit = %lld, number of terms = ",++test,a,limit);
		count=1;
		while (a>1&&a<=limit)
		{
			if (a%2==0) a/=2;
			else a=3*a+1;
			if (a<=limit) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
