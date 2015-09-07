#include <cstdio>
#define MAXN 3005

double c[MAXN];

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	int n;
	double x,y;
	double ans;
	scanf("%d",&n);
	scanf("%lf%lf",&x,&y);
	c[0]=0;
	for (int i=1; i<=n; i++)
	{
	    scanf("%lf",&c[i]);
	    c[i]+=c[i-1];
	}
	for (int i=1; i<=n; i++) c[i]+=c[i-1];
	ans=(x*n+y-2*c[n])/(n+1);
	printf("%.2f\n",ans);
	if (test) printf("\n");
    }
    return 0;
}
