#include <cmath>
#include <cstdio>

const double eps=1e-9;

double calc(double x1,double y1,double x2,double y2)
{
	return (x1+x2+y1-y2)/2;
}

int main()
{
	double x[4],y[4];
	while (scanf("%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1])==4)
	{
		if (fabs(x[0]-x[1])<eps&&fabs(y[0]-y[1])<eps)
		{
			printf("Impossible.\n");
			continue;
		}
		x[2]=calc(x[0],y[0],x[1],y[1]);
		x[3]=calc(x[1],y[1],x[0],y[0]);
		y[3]=calc(y[0],x[0],y[1],x[1]);
		y[2]=calc(y[1],x[1],y[0],x[0]);
		printf("%.10lf %.10lf %.10lf %.10lf\n",x[2],y[2],x[3],y[3]);
	}  
	return 0;
}
