#include <cstdio>
#include <cstring>

char s1[100],s2[100];
int a[100],b[100];

void add()
{
    int i=1,x=0;
    if (b[0]>a[0]) a[0]=b[0];
    for (i=1;i<=a[0];i++)
    {
        a[i]+=b[i]+x;
        x=a[i]/10;
        a[i]%=10;
    }
    if (x) { a[0]++; a[a[0]]=x; }
}

int main()
{
    int N,i;
    scanf("%d",&N);
    while (N--)
    {
        scanf("%s%s",s1,s2);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        a[0]=strlen(s1);
        b[0]=strlen(s2);
        for (i=1;i<=a[0];i++) a[i]=s1[i-1]-'0';
        for (i=1;i<=b[0];i++) b[i]=s2[i-1]-'0';
        add();
        for (i=1;i<=a[0];i++)
            if (a[i]) break;
        for (;i<=a[0];i++)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
