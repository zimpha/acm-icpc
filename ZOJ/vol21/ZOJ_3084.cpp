#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 10001
#define MAXK 101

int s[MAXK];
int sg[SIZE];
int count[MAXK];
int k,l,h,m;

int main()
{
    int i,j;
    int tmp;
    while (scanf("%d",&k)!=EOF&&k)
    {
        for (i=1;i<=k;i++)
            scanf("%d",&s[i]);
        memset(sg,0,sizeof(sg));
        for (i=1;i<SIZE;i++)
        {
            memset(count,0,sizeof(count));
            for (j=1;j<=k;j++)
                if (i-s[j]>=0) count[sg[i-s[j]]]++;
            for (j=0;j<=k;j++)
                if (!count[j])
                {
                    sg[i]=j;
                    break;
                }
        }
        scanf("%d",&m);
        while (m--)
        {
            scanf("%d",&l);
            tmp=0;
            for (i=0;i<l;i++)
            {
                scanf("%d",&h);
                tmp^=sg[h];
            }
            if (tmp) printf("W");
            else printf("L");
        }
        printf("\n");
    }
    return 0;
}
