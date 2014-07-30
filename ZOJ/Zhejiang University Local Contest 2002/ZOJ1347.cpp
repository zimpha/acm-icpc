#include <cstdio>

double eps=0.01;

int main()
{
	int N ;
	scanf("%d", &N ) ;
	while( N-- )
	{
		double n, m, p, r, s;
		double price, audiences, revenue=0;
		scanf("%lf%lf%lf%lf%lf", &n, &p, &m, &r, &s);
		double x=(p*n+m*s)/(2.0*p*m);
		for (int k=(int)x-10; k<(int)x+10; k++)
		{
			double a=p*k-eps;
			double b=n-m*(k-1);
			double c=a*b-r-s*b;
			if (c>revenue)
			{
				price=a;
				audiences=b;
				revenue=c;
			}
		}
		printf("price = %.2lf\n", price);
		printf("audiences = %.0lf\n", audiences);
		printf("revenue = %.2lf\n", revenue) ;
		if (N) puts("");
	}
	return 0 ;
}
