#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100000
#define SIZE 5000001

int p[SIZE];
int a[MAXN];
int fact[SIZE];
int n,m;

void GetPrime()
{
    m=0;
    memset(p,0,sizeof(p));
    for (int i=2;i<SIZE;i++)
        if (!p[i])
        {
            p[m++]=i;
            for (int j=i;j<SIZE;j+=i)
            {
                if (!p[j]) fact[j]=i;
                p[j]=1;
            }
        }
}

int sg(int n)
{
    int sum=0;
    for (int i=0;i<m;i++)
        if (n%p[i]==0)
        {
            while (n%p[i]==0)
            {
                sum++;
                n/=p[i];
            }
            if (n==1) break;
        }
    if (n>1) sum++;
    return sum;
}

int GetSG(int n)
{
    int s=0;
    while (n>1)
    {
        s++;
        n/=fact[n];
    }
    return s;
}

int main()
{
    int i,sum;
    int test=0;
    GetPrime();
    while (scanf("%d",&n)!=EOF)
    {
        for (sum=i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]=GetSG(a[i]);
            sum^=a[i];
        }
        printf("Test #%d: ",++test);
        if (!sum) printf("Bob");
        else
        {
            printf("Alice");
            for (i=0;i<n;i++)
                if (a[i]>=(sum^a[i]))
                {
                    printf(" %d",i+1);
                    break;
                }
        }
        printf("\n");
    }
    return 0;
}
