#include <cstdio>
#include <cstring>
#define MAXN 40

int f[MAXN][8];
int n;

int main()
{
    int i;
    while (scanf("%d",&n)&&n!=-1)
    {
        memset(f,0,sizeof(f));
        f[0][7]=1;
        for (i=1;i<=n;i++)
        {
            f[i][7]=f[i-1][0]+f[i-1][3]+f[i-1][6];
            f[i][0]=f[i-1][7];
            f[i][3]=f[i-1][7]+f[i-1][4];
            f[i][6]=f[i-1][7]+f[i-1][1];
            f[i][4]=f[i-1][3];
            f[i][1]=f[i-1][6];
        }
        printf("%d\n",f[n][7]);
    }
    return 0;
}
