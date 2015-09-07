#include <cmath>
#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1&&n)
    {
	n=n/10-196+2;
	double len=pow(2.0,n)*log10(2.0);
	double sum=0;
	for (int fac=1;;fac++)
	{
	    sum+=log10(fac*1.0);
	    if (sum>len)
	    {
		printf("%d\n",fac-1);
		break;
	    }
	}
    }
    return 0;
}
