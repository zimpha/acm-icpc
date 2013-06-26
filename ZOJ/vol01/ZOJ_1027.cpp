#include <cstdio>
#include <cstring>

const int w[5][5]={5,-1,-2,-1,-3,-1,5,-3,-2,-4,-2,-3,5,-2,-2,-1,-2,-2,5,-1,-3,-4,-2,-1,0};
const int MAXN=105;
const int inf=10000000;

int f[MAXN][MAXN];
char s1[MAXN],s2[MAXN];
int n,m;

int val(char c)
{
    if (c=='A') return 0;
    if (c=='C') return 1;
    if (c=='G') return 2;
    if (c=='T') return 3;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d %s",&n,s1+1);
	scanf("%d %s",&m,s2+1);
	for (int i=0; i<=n; i++)
	    for (int j=0; j<=m; j++)
		f[i][j]=-inf;
	f[0][0]=0;
	for (int i=0; i<=n; i++)
	    for (int j=0; j<=m; j++)
	    {
		if (i>=1) f[i][j]=f[i-1][j]+w[val(s1[i])][4];
		if (j>=1) f[i][j]=max(f[i][j],f[i][j-1]+w[val(s2[j])][4]);
		if (i>=1&&j>=1) f[i][j]=max(f[i][j],f[i-1][j-1]+w[val(s1[i])][val(s2[j])]);
	    }
	printf("%d\n",f[n][m]);
    }
    return 0;
}
