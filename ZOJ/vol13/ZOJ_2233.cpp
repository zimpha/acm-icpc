#include <cstdio>
#include <cstring>

const int MAXN=105;

double mat[MAXN][MAXN];
double tank[MAXN];
int d[MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		for (int i=0; i<n; i++)
			scanf("%lf", tank+i);
		memset(d,0,sizeof(d));
		memset(mat,0,sizeof(mat));
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			d[--a]++; d[--b]++;
			mat[a][b]=mat[b][a]=1;
		}
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (d[i]) mat[i][j]/=d[i];
		for (m=0; m<20; m++)
		{
			double a[MAXN][MAXN];
			double b[MAXN][MAXN];
			memcpy(a,mat,sizeof(mat));
			memcpy(b,mat,sizeof(mat));
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
				{
					mat[i][j]=0;
					for (int k=0; k<n; k++)
						mat[i][j]+=a[i][k]*b[k][j];
				}
		}
		for (int i=0; i<n; i++)
		{
			double ret=0;
			for (int j=0; j<n; j++)
				ret+=tank[j]*mat[j][i];
			if (!d[i]) ret=tank[i];
			printf("%.3f\n", ret);
		}
		puts("");
	}
	return 0;
}
