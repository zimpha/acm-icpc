#include <cstdio>
#define MAXN 20

int a[MAXN];
int n;

int main()
{
    int test;
    int i,flag;
    int count;
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        flag=0;
        count=0;
        for (i=0;i<n;i++)
            if (a[i]) count++;
            else break;
        if (count&1) flag=1;
        count=0;
        for (i=n-1;i>=0;i--)
            if (a[i]) count++;
            else break;
        if (count&1) flag=1;
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
