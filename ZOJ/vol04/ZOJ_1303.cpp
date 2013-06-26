#include <cstdio>
#include <cstring>

const int MAXN=201;
const int MAXM=21;
const int MAXD=810;
const int DELTA=400;

int f[MAXN][MAXM][MAXD];
int p[MAXN][MAXM][MAXD];
int diff[MAXN];
int sum[MAXN];
int ans[MAXM];
int n,m;

int min(int a, int b)
{
    return (a<b)?a:b;
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&n,&m)==2&&n)
    {
	memset(diff,0,sizeof(diff));
	memset(sum,0,sizeof(sum));
	for (int i=1; i<=n; i++)
	{
	    int a,b;
	    scanf("%d%d",&a,&b);
	    diff[i]=a-b; sum[i]=a+b;
	}
	int st=DELTA-20*m, en=DELTA+20*m;
	memset(f,-1,sizeof(f));
	memset(p,0,sizeof(p));
	for (int i=1; i<=n; i++)
	{
	    for (int k=st; k<=en; k++)
		f[i][1][k]=f[i-1][1][k];
	    if (sum[i]>f[i][1][diff[i]+DELTA])
	    {
		p[i][1][diff[i]+DELTA]=i;
		f[i][1][diff[i]+DELTA]=sum[i];
	    }
	    for (int j=2; j<=min(i,m); j++)
	    {
		for (int k=st; k<=en; k++)
		{
		    if (k-diff[i]>=st&&k-diff[i]<=en)
		    {
			int a=f[i-1][j][k];
			int b=f[i-1][j-1][k-diff[i]];
			if (b==-1) f[i][j][k]=a;
			else if (a>=b+sum[i]) f[i][j][k]=a;
			else f[i][j][k]=b+sum[i], p[i][j][k]=i;
		    }
		    else f[i][j][k]=f[i-1][j][k];
		}
	    }
	}
	int delta=0;
	int pro, def, d;
	while (f[n][m][DELTA+delta]==-1&&f[n][m][DELTA-delta]==-1) delta++;
	if (f[n][m][DELTA+delta]>f[n][m][DELTA-delta])
	{
	    pro=(f[n][m][DELTA+delta]+delta)/2;
	    def=(f[n][m][DELTA+delta]-delta)/2;
	    d=DELTA+delta;
	}
	else
	{
	    pro=(f[n][m][DELTA-delta]-delta)/2;
	    def=(f[n][m][DELTA-delta]+delta)/2;
	    d=DELTA-delta;
	}
	printf("Jury #%d\n",++cas);
	printf("Best jury has value %d for prosecution and value %d for defence:\n",pro,def);
	int j=m;
	while (j)
	{
	    int x=p[n][j][d];
	    if (x>0)
	    {
		ans[j]=x;
		d-=diff[x];
		j--;
	    }
	    n--;
	}
	for (int i=1; i<=m; i++)
	    printf(" %d",ans[i]);
	printf("\n\n");
    }
    return 0;
}
