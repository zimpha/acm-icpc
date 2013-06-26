#include <cstdio>
#define MAXM 1000

int a[MAXM];
int m;

int main()
{
    int i,tmp;
    while (scanf("%d",&m)!=EOF&&m)
    {
        tmp=0;
        for (i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            tmp^=a[i];
        }
        if (tmp)
        {
            int count=0;
            for (i=0;i<m;i++)
                if ((tmp^a[i])<=a[i])
                    count++;
            printf("%d\n",count);
        }
        else printf("0\n");
    }
    return 0;
}
