#include <cmath>
#include <cstdio>

const double eps=1e-8;

int main()
{
    double h,m;
    while (scanf("%lf:%lf",&h,&m)==2&&h>eps)
    {
	if (h==12) h=0;
	double ans=fabs(h*30.0+m/2.0-m*6.0);
	if (ans>180) ans=360.0-ans;
	printf("%.3f\n",ans);
    }
    return 0;
}
