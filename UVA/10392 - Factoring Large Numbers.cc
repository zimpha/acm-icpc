#include <cstdio>
#include <cstring>

const int MAXN=1000000;

typedef long long LL;

bool hash[MAXN];
int p[MAXN];
int size;

void sieve()
{
    memset(hash,0,sizeof(hash));
    size=0;
    for (int i=2; i<MAXN; i++)
	if (!hash[i])
	{
	    p[size++]=i;
	    for (int j=i; j<MAXN; j+=i)
		hash[j]=1;
	}
}

int main()
{
    LL n;
    sieve();
    while (scanf("%lld",&n)&&n>0)
    {
	if (n==1)
	{
	    printf("    1\n\n");
	    continue;
	}
	for (int i=0; i<size; i++)
	    if (n%(LL)p[i]==0)
	    {
		while (n%(LL)p[i]==0)
		{
		    n/=(LL)p[i];
		    printf("    %d\n",p[i]);
		}
	    }
	if (n>1) printf("    %lld\n",n);
	printf("\n");
    }
    return 0;
}
