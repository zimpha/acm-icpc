#include <cstdio>

int main()
{
    int test,n;
    int ans,tmp;
    scanf("%d",&test);
    while (test--)
    {
        ans=0; tmp=5;
        scanf("%d",&n);
        while (n/tmp)
        {
            ans+=n/tmp;
            tmp*=5;
        }
        printf("%d\n",ans);
    }
    return 0;
}
