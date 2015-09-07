#include <cstdio>
#include <cstring>
#define SIZE 1000

long a[SIZE];
char s[SIZE],opt;
long n;

int main()
{
    while (scanf("%s %c %ld",s,&opt,&n)!=EOF)
    {
        a[0]=strlen(s);
        for (int i=0;i<a[0];i++)
            a[i+1]=s[i]-'0';
        long x=0;
        for (int i=1;i<=a[0];i++)
        {
            x=x*10+a[i];
            a[i]=x/n;
            x=x%n;
        }
        if (opt=='/')
        {
            int i;
            for (i=1;i<a[0]&&!a[i];i++);
            for (;i<=a[0];i++)
                printf("%ld",a[i]);
            printf("\n");
        }
        else printf("%ld\n",x);
    }
    return 0;
}
