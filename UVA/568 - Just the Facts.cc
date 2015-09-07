#include <cmath>
#include <cstdio>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
	int two=0,five=0;
	for (int i=5; n/i; i*=5)
	    five+=n/i;
	two=five;
	int digit=1;
	for (int i=1; i<=n; i++)
	{
	    int tmp=i;
	    while (tmp%2==0&&two)
	    {
		tmp/=2;
		two--;
	    }
	    while (tmp%5==0&&five)
	    {
		tmp/=5;
		five--;
	    }
	    digit=digit*tmp%10;
	}
	printf("%5d -> %d\n",n,digit);
    }
    return 0;
}
