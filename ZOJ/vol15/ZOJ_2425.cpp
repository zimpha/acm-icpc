#include <stdio.h>

int n,m;

int main()
{
    int i,p,tmp;
    while (scanf("%d%d",&n,&m)&&n!=-1)
    {
        p=1;
        int count=0;
        while (p*(p-1)/2<m) p++;
        tmp=p*(p-1)/2;
        for (i=1;i<=n-p;i++)
        {
        	count++;
            printf("%d",i);
            if (count==n) putchar('\n');
            else putchar(' ');
        }
        count++;
        printf("%d",n-tmp+m);
        if (count==n) putchar('\n');
        else putchar(' ');
        for (i=n;i>n-p;i--)
            if (i!=n-tmp+m)
           	{
           		count++;
                printf("%d",i);
                if (count==n) putchar('\n');
            	else putchar(' ');
            }
    }
    return 0;
}
