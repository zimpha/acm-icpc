#include <cstdio>

int main()
{
    int p,e,i,d;
    int test;
    scanf("%d", &test);
    while (test--)
    {
		int cas=0;
		while (scanf("%d%d%d%d",&p,&e,&i,&d)==4&&p>=0)
    	{
			int n=(5544*p+14421*e+1288*i-d+21252)%21252;
			if (n==0) n=21252;
			printf("Case %d: the next triple peak occurs in %d days.\n",++cas,n);
    	}
    	if (test) puts("");
    }
    return 0;
}
