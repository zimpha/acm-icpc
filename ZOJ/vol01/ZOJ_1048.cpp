#include <cstdio>

int main()
{
    double ans=0,tmp;
    int i;
    for (i=0;i<12;i++)
    {
        scanf("%lf",&tmp);
        ans+=tmp;
    }
    ans/=12;
    printf("$%.2lf\n",ans);
    return 0;
}
