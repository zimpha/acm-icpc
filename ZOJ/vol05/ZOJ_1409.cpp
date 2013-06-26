#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

const int MAXN=105;
const int MAXB=505;
const int inf=100000000;

int f[MAXN][MAXB];
int p[MAXN][MAXN];
int b[MAXN][MAXN];
int m[MAXN];
int n,upper;

int main()
{
	int test;
	scanf("%d",&test);
	while (test--)
	{
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
		{
			scanf("%d",m+i);
			for (int j=1; j<=m[i]; j++)
			{
				scanf("%d%d",&b[i][j],&p[i][j]);
				upper=max(upper,b[i][j]);
			}
		}

		for (int i=0; i<=upper; i++) f[1][i]=inf;
		for (int i=1; i<=m[1]; i++) f[1][b[1][i]]=min(f[1][b[1][i]],p[1][i]);
		for (int i=2; i<=n; i++)
			for (int j=0; j<=upper; j++)
			{
				f[i][j]=inf;
				for (int k=1; k<=m[i]; k++)
					f[i][min(j,b[i][k])]=min(f[i][min(j,b[i][k])],f[i-1][j]+p[i][k]);
			}
		double ans=0;
		for (int i=0; i<=upper; i++)
			if (ans<1.0*i/f[n][i])
				ans=1.0*i/f[n][i];
		printf("%.3f\n",ans);
	}
	return 0;
}
