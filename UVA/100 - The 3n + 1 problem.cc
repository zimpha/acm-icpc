#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1000000;

int f[MAXN];

int calc(long long n)
{
    if (n==1) return 1;
    if (n&1) return calc(3*n+1)+1;
    else return calc(n/2)+1;
}

int main()
{
    int a,b;
    memset(f,0,sizeof(f));
    while (scanf("%d%d",&a,&b)==2)
    {
	printf("%d %d ",a,b);
	if (a>b) std::swap(a,b);
	int ans=0;
	for (int i=a; i<=b; i++)
	{
	    if (!f[i]) f[i]=calc(i);
	    ans=std::max(ans,f[i]);
	}
	printf("%d\n",ans);
    }
    return 0;
}
