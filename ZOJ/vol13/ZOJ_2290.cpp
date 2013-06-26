#include <cstdio>

int fib[40];

int main()
{
    int n,i,ans;
    int count;
    fib[0]=1; fib[1]=2;
    for (i=2;i<40;i++)
        fib[i]=fib[i-1]+fib[i-2];
    while (scanf("%d",&n)!=EOF)
    {
        count=0;
        for (i=39;i>=0;i--)
            if (n>=fib[i])
            {
                n-=fib[i];
                if (n==0) ans=fib[i];
                count++;
            }
        if (count==1) printf("lose\n");
        else printf("%d\n",ans);
    }
    return 0;
}
