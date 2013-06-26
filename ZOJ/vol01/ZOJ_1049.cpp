#include <cstdio>
#include <cmath>
#define PI 3.1415926535897932

int main()
{
    int test,i;
    double x,y;
    scanf("%d",&test);
    for (i=1;i<=test;i++)
    {
        scanf("%lf%lf",&x,&y);
        printf("Property %d: This property will begin eroding in year %.0lf.\n",i,ceil(PI*(x*x+y*y)/100));
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
