#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 50000

using namespace std;

int main()
{
    char str[MAXN];
    long long f[MAXN];
    int i,n,tmp;
    while (scanf("%s",str+1)&&str[1]!='0')
    {
        n=strlen(str+1);
        f[0]=f[1]=1;
        for (i=2;i<=n;i++)
        {
            if (str[i]=='0')
            {
                if (str[i-1]=='1'||str[i-1]=='2') f[i]=f[i-2];
                else f[i]=f[i-1];
            }
            else
            {
                f[i]=f[i-1];
                tmp=(str[i-1]-'0')*10+str[i]-'0';
                if (tmp>10&&tmp<27) f[i]+=f[i-2];
            }
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
