#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,v,t;
double ans;

int main()
{
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        ans=1e20;
        while (n--)
        {
            scanf("%d%d",&v,&t);
            if ((t>=0)&&(ans>4.5/v*3600+t)) ans=4.5/v*3600+t;
        }
        printf("%.0lf\n",ceil(ans));
    }
    return 0;
}
