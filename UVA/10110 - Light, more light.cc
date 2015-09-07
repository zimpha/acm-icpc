#include <cmath>
#include <cstdio>

int main()
{
    long n,m;
    while (scanf("%ld",&n)==1&&n)
    {
	m=sqrt(n);
	if (m*m==n) printf("yes\n");
	else printf("no\n");
    }	
    return 0;
}
