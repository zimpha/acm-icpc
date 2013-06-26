#include<stdio.h>

typedef long long LL;

const LL mod = 1000000007;
const int MAXK=55;

LL C[MAXK][MAXK];

LL power(LL n, LL k)
{
    if (k==0) return 1;
    LL res=power(n, k>>1);
    res =(res*res)%mod;
    if (k&1) res=(res*n)%mod;
    return res;
}

LL ext_gcd(LL a, LL b, LL& x, LL& y)
{
	LL t,ret;
    if (!b)
    {
		x=1,y=0;
        return a;
	}
	ret=ext_gcd(b,a%b,x,y);
	t=x, x=y, y=t-a/b*y;
    return ret;
}

void calc_com()
{
    for (int i=0; i<MAXK; i++)
		C[0][i]=0, C[i][0]=1;
	for(int i=1; i<MAXK; i++)
        for(int j=1; j<MAXK; j++)
             C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
}

int main(void)
{
    int test;
    
    calc_com();
    scanf("%d", &test);
    while (test--)
    {
    	LL n,k;
    	scanf("%lld%lld", &n, &k);
        LL ans[MAXK];
		ans[0]=n%mod; ans[1]=n*(n+1)/2%mod;
        for (int i=2; i<=k; i++)
		{
			LL ret = power(n,i+1);
            for (int j=2; j<=i+1; j++)
            {
            	if (j&1) ret=(ret-C[i+1][j]*ans[i+1-j]%mod+mod)%mod;
                else ret=(ret+C[i+1][j]*ans[i+1-j]%mod+mod)%mod;
            }
            LL a=C[i+1][1], b=ret, x, y;
            ext_gcd(a, mod, x, y);
            x=(x%mod+mod)%mod;
            ans[i]=(x*b+mod)%mod;
        }
        printf("%lld\n", ans[k]);
    }
    return 0;
}
