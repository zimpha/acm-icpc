#include <cstdio>
#include <cmath>

int main()
{
    int n,m;
    int test,i;
    scanf("%d",&test);
    for (i=1;i<=test;i++)
    {
        scanf("%d%d",&n,&m);
        printf("Scenario #%d:\n",i);
        if (m*n%2==0) printf("%.2f\n",1.0*n*m);
        else printf("%.2f\n",0.41+n*m);
        printf("\n");
    }
    return 0;
}
