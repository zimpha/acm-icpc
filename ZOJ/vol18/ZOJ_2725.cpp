#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1000000

bool f[MAXN];
char s[10],t[10];

void calc()
{
    int i,l,j,k;
    char c,wei;
    bool flag;
    f[0]=true;
    for (i=1;i<MAXN;i++)
    {
        flag=true;
        sprintf(s,"%d",i);
        l=strlen(s);
        for (j=0;j<l&&flag;j++)
        {
            wei=s[j];
            c='0';
            if (j==0) c++;
            if (wei=='0')
            {
                for (k=0;k<j;k++) t[k]=s[k];
                t[j]='\0';
                flag=f[atoi(t)];
            }
            else
            {
                for (;c<wei&&flag;c++)
                {
                    s[j]=c;
                    flag=f[atoi(s)];
                }
            }
            s[j]=wei;
        }
        f[i]=!flag;
    }
}

int main()
{
    int n;
    bool flag;
    calc();
    while (scanf("%s",s)!=EOF)
    {
        flag=true;
        if (s[0]=='0') flag=true;
        else
        {
            n=atoi(s);
            flag=f[n];
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
