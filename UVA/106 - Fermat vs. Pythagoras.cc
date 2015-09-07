#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1000005

bool hash[MAXN];
int n;

int gcd(int a,int b)
{
    if (!b) return a;
    else return gcd(b,a%b);
}

bool judge(int a,int b,int c)
{
    int tmp=gcd(a,b);
    if (gcd(tmp,c)==1) return 1;
    else return 0;
}

void get_triple()
{
    int ans=0;
    int limit=sqrt(n+0.5);
    for (int i=1; i<=limit; i++)
	for (int j=i+1; j<=limit; j++)
	{
	    int a=j*j-i*i;
	    int b=2*i*j;
	    int c=i*i+j*j;
	    if (c>n) break;
	    if (judge(a,b,c))
	    {
		ans++;
		for (int k=1; k*c<=n; k++)
		    hash[k*a]=hash[k*b]=hash[k*c]=1;
	    }
	}
    printf("%d",ans);
}

void get_p()
{
    int ans=0;
    for (int i=1; i<=n; i++)
	if (!hash[i]) ans++;
    printf(" %d\n",ans);
}

int main()
{
    while (scanf("%d",&n)==1)
    {
	memset(hash,0,sizeof(hash));
	get_triple();
	get_p();
    }
    return 0;
}

