#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

int a[1000];
char s[10];
int n,b;

void mul(int n)
{
    int i,x=0;
    for (i=1;i<=a[0];i++)
    {
        a[i]=a[i]*n+x;
        x=a[i]/10;
        a[i]=a[i]%10;
    }
    while (x)
    {
        a[0]++;
        a[a[0]]=x%10;
        x=x/10;
    }
}

int main()
{
    int point,i;
    int l, r;

    while (scanf("%s %d",s,&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        b=point=0;
        l=0; r=5;
        while (s[l]=='0') l++;
        while (s[r]=='0') r--;

        for (i=r;i>=l;i--)
            if (s[i]=='.') point=r-i;
            else
            {
                a[0]++;
                a[a[0]]=s[i]-'0';
            }

        for (i=l;i<=r;i++)
            if (s[i]!='.') b=b*10+s[i]-'0';

        for (i=1;i<n;i++)
            mul(b);
        point=point*n;
        while (a[a[0]]==0) a[0]--;
        if (a[0]<point) a[0]=point;
        for (i=a[0];i>point;i--) printf("%d",a[i]);
        if (point>0) printf(".");
        for (i=point;i>0;i--) printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
