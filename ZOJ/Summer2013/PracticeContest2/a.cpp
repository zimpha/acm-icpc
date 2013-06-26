#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN=55;
const int inf=1000000000;

int dis[MAXN][MAXN];
int tx[MAXN], ty[MAXN];
int gx, gy, wt, tt;
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", tx+i);
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d", ty+i);
		scanf("%d%d%d%d", &gx, &gy, &wt, &tt);
		if (tt>wt) tt=wt;
		n++;
		for (int i=0; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
				dis[i][j]=dis[j][i]=inf;
			dis[i][i]=0;
		}
		for (int i=1; i<n; i++)
		{
			dis[0][i]=dis[i][0]=wt*(abs(tx[i])+abs(ty[i]));
			dis[i][n]=tt*(abs(tx[i]-gx)+abs(ty[i]-gy));
		}
		dis[0][n]=wt*(abs(gx)+abs(gy));
		for (int i=1; i<n; i++)
			for (int j=1; j<n; j++)
				dis[i][j]=tt*(abs(tx[i]-tx[j])+abs(ty[i]-ty[j]));
		for (int k=0; k<=n; k++)
			for (int i=0; i<=n; i++)
				for (int j=0; j<=n; j++)
					if (dis[i][j]>dis[i][k]+dis[k][j])
						dis[i][j]=dis[i][k]+dis[k][j];
		printf("%d\n", dis[0][n]);
	}
	return 0;
}
