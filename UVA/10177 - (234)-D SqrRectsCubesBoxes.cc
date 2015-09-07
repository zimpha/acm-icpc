#include <cstdio>

int main()
{
    long long n;
    while (scanf("%lld",&n)==1)
    {
	printf("%lld %lld ",n*(n+1)*(2*n+1)/6,n*n*(n+1)*(n+1)/4-n*(n+1)*(2*n+1)/6);
	printf("%lld %lld ",n*n*(n+1)*(n+1)/4,n*n*n*(n+1)*(n+1)*(n+1)/8-n*n*(n+1)*(n+1)/4);
	printf("%lld %lld\n",n*(n+1)*(2*n+1)*(3*n*n+3*n-1)/30,n*n*n*n*(n+1)*(n+1)*(n+1)*(n+1)/16-n*(n+1)*(2*n+1)*(3*n*n+3*n-1)/30);
    }
    return 0;
}
