#include <cmath>
#include <cstdio>
#include <cstring>

const double e=exp(1.0);
const double eps=1e-14;
int main()
{
	double a;
	while (scanf("%lf", &a)==1)
	{
		if (a>=e) puts("-1");
		else
		{
			a=log(a)/a;
			double left=e;
			double right=44;
			double mid;
			while (left<=right+eps)
			{
				mid=(left+right)/2.0;
				double tmp=log(mid)/mid;
				if (fabs(tmp-a)<=eps) break;
				if (tmp>a) left=mid;
				else right=mid;
			}
			printf("%.5f\n", mid);
		}
	}
	return 0;
}
