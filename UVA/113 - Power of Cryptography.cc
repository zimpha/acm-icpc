#include <cmath>
#include <cstdio>

int main()
{
    double n,p;
    while (scanf("%lf%lf",&n,&p)==2)
    {
	int l=0, r=1000000000;
	while (l<r)
	{
	    int m=(l+r)/2;
	    if (pow(m,n)>=p) r=m;
	    else l=m+1;
	}
	printf("%d\n",r);
    }
    return 0;
}
