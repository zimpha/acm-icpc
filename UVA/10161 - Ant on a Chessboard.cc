#include <cstdio>
#include <cmath>

int main()
{
    int n;
    while (scanf("%d",&n)==1&&n)
    {
	int k=sqrt(n);
	int delta=n-k*k;
	int x,y;
	if (delta<0) k--,delta=n-k*k;
	if (k&1)
	{
	    x=1; y=k;
	    if (delta>0) y++,delta--;
	    if (delta>=k) x=k+1,y-=delta-k;
	    else if (delta>0) x=delta+1;
	}
	else
	{
	    y=1; x=k;
	    if (delta>0) x++,delta--;
	    if (delta>=k) y=k+1,x-=delta-k;
	    else if (delta>0) y=delta+1;
	}
	printf("%d %d\n",x,y);
    }
    return 0;
}
