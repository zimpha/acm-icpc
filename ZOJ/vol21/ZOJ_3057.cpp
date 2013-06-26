#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 301

using namespace std;

bool f[MAXN][MAXN][MAXN];
int a,b,c;

void calc()
{
    int i,j,k,d;
    for (i=0;i<MAXN;i++)
    {
        for (j=0;j<MAXN;j++)
        {
            for (k=0;k<MAXN;k++)
                if (!f[i][j][k])
                {
                    for (d=1;d+i<MAXN;d++)
                        f[d+i][j][k]=1;
                    for (d=1;d+j<MAXN;d++)
                        f[i][d+j][k]=1;
                    for (d=1;d+k<MAXN;d++)
                        f[i][j][d+k]=1;
                    for (d=1;d+i<MAXN&&d+j<MAXN;d++)
                        f[d+i][d+j][k]=1;
                    for (d=1;d+j<MAXN&&d+k<MAXN;d++)
                        f[i][d+j][d+k]=1;
                    for (d=1;d+i<MAXN&&d+k<MAXN;d++)
                        f[d+i][j][d+k]=1;
                }
        }
    }
}

int main()
{
    memset(f,0,sizeof(f));
    calc();
    while (scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if (f[a][b][c]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
