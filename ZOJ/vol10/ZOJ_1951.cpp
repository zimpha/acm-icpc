#include <stdio.h>
#define MAXN 1000010

int prime[MAXN];
int n;

void sieve()
{
    int i,j;
    for (i=1;i<MAXN;i++) prime[i]=1;
    for (i=2;i<MAXN;i++)
        if (prime[i])
        {
            for (j=i*2;j<MAXN;j+=i)
                prime[j]=0;
        }
}

int main()
{
    int i,flag;
    sieve();
    while (scanf("%d",&n)!=EOF&&n)
    {
        flag=0;
        for (i=3;i<=n/2;i++)
            if (prime[i]&&prime[n-i])
            {
                printf("%d = %d + %d\n",n,i,n-i);
                flag=1;
                break;
            }
        if (!flag) printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}
