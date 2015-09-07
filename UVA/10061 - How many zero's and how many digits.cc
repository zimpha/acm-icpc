#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=800;
const double eps=1e-8;

bool hash[MAXN];
int count[MAXN];
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

int get(int n,int fact)
{
    int sum=0;
    for (int i=fact; n/i; i*=fact)
	sum+=n/i;
    return sum;
}

int main()
{
    int n,m,base;
    sieve();
    while (scanf("%d%d",&n,&base)==2)
    {
	double len=0;
	for (int i=1; i<=n; i++)
	    len+=log10(i);
	len/=log10(base);
	memset(count,0,sizeof(count));
	for (int i=0; i<size; i++)
	    if (base%p[i]==0)
	    {
		while (base%p[i]==0)
		{
		    base/=p[i];
		    count[i]++;
		}
	    }
	int ans=n;
	for (int i=0; i<size; i++)
	    if (count[i])
	    {
		int tmp=get(n,p[i]);
		if (tmp/count[i]<ans) ans=tmp/count[i];
	    }
	printf("%d %.0f\n",ans,floor(len+eps)+1);
    }
    return 0;
}
