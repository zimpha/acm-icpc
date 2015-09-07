#include <cmath>
#include <cstdio>

const double eps=1e-8;

int main()
{
    int s,h;
    while (scanf("%d%d",&h,&s)&&s&&h)
    {
	int n,k,m;
	double a,b;
	if (s==1&&(h&1))
	{
	    printf("0 %d\n",h);
	    continue;
	}
	for (k=1;;k++)
	{
	    a=pow(s,1.0/k);
	    b=pow(h,1.0/k);
	    if (fabs(b-a-1)<eps) break;
	}
	n=(int)(a+eps);
	m=(int)(b+eps);
	if (fabs(a-1)<eps) printf("%d %d\n",k,m*h-n*s);
	else printf("%d %d\n",(s-1)/(n-1),m*h-n*s);
    }
    return 0;
}
