#include <cmath>
#include <cstdio>

const double Pi=acos(-1.0);
const double eps=1e-6;

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
    	double B,H,L;
	scanf("%lf%lf",&B,&H);
	L=sqrt(B*B/4+H*H);
	double k=B/(B+2*L);
	double p=H,r=p*k;
	while (r>=eps)
	{
	    p=p-2*r;
	    r=p*k;
	}
	double C=Pi*(H-r/k);
	printf("%13.6lf\n",C);
	if (test) putchar('\n');
    }
    return 0;
}
