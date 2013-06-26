#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

int main()
{
    double x1,x2,x3;
    double y1,y2,y3;
    double a,b,c;
    double CosA;
    while (scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        b=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        c=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        CosA=(b*b+c*c-a*a)/(2*b*c);
        printf("%.2lf\n",PI*a/sqrt(1-CosA*CosA));
    }
    return 0;
}
