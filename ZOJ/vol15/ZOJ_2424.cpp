#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
#define MAXN 200

int n,m;
int a[SIZE];
int p[MAXN];
int c[MAXN];

void get_prime()
{
    int i,j;
    m=0;
    memset(p,1,sizeof(p));
    for (i=2;i<MAXN;i++)
        if (p[i])
        {
            p[m++]=i;
            for (j=i+i;j<MAXN;j+=i)
                p[j]=0;
        }
}

void mul(int n)
{
    int i,x=0;
    for (i=1;i<=a[0];i++)
    {
        a[i]=a[i]*n+x;
        x=a[i]/10;
        a[i]=a[i]%10;
    }
    while (x)
    {
        a[0]++;
        a[a[0]]=x%10;
        x=x/10;
    }
}

int main()
{
    int i,j;
    get_prime();
    while (scanf("%d",&n)&&n>0)
    {
        memset(a,0,sizeof(a));
        a[0]=a[1]=1;
        memset(c,0,sizeof(c));
        for (i=0;i<m;i++)
        {
            j=p[i];
            while (2*n/j)
            {
                c[i]+=2*n/j;
                c[i]-=n/j+(n+1)/j;
                j*=p[i];
            }
        }
        for (i=0;i<m;i++)
            for (j=1;j<=c[i];j++)
                mul(p[i]);
        for (i=a[0];i>0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
