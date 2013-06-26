#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=205;
const int MAXM=35;
const int inf=100000000;

int cost[MAXN][MAXN];
int f[MAXN][MAXM];
int p[MAXN][MAXM];
int x[MAXN];
int n, m;

int mincost(int a,int b)
{
    int i,s=0,mid;
    mid=(a+b)/2;
    for (i=a;i<=b;i++)
        s+=abs(x[i]-x[mid]);
    return s;
}

int main()
{
	int cas=0;
    while (scanf("%d%d", &n, &m)==2&&n)
	{
		for (int i=1; i<=n; i++)
			scanf("%d", x+i);

		memset(f,0,sizeof(f));
		memset(p,-1,sizeof(p));
		memset(cost,0,sizeof(cost));
		for (int i=1; i<=n; i++)
			for (int j=i+1; j<=n; j++)
				cost[i][j]=mincost(i,j);
		p[1][1]=0;
		for (int i=2; i<=n; i++)
		{
			f[i][1]=cost[1][i];
			p[i][1]=0;
			for (int j=2; j<=std::min(i,m); j++)
			{
				f[i][j]=inf;
				for (int k=j-1; k<i; k++)
					if (f[i][j]>f[k][j-1]+cost[k+1][i])
					{
						f[i][j]=f[k][j-1]+cost[k+1][i];
						p[i][j]=k;
					}
			}
		}
		printf("Chain %d\n", ++cas);
		printf("Total distance sum = %d\n\n", f[n][m]);
	}
    return 0;
}
