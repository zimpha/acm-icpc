#include <cstdio>

int main()
{
    long long x,y;
    int cas=0;
    while (scanf("%lld%lld",&x,&y)==2&&x&&y)
    {
	printf("Case %d: %lld\n",++cas,x*(x-1)*y*(y-1)/4);
    }
    return 0;
}
