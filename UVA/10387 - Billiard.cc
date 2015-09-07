#include<cmath>
#include<cstdio>

const double Pi=acos(-1.0);

int main()
{
    double a, b, s, m, n, A, v;
    while (scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n)&&a)
    {
	double aa=a*m, bb=b*n;
	A=atan(bb/aa)*180/Pi;
	v=sqrt(bb*bb+aa*aa)/s;
	printf("%.2lf %.2lf\n",A,v);
    }
    return 0;
}
