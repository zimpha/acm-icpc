#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=405;
const int MAXM=10005;
const double inf=1e20;
const double eps=1e-5;

struct EDGET
{
	int c, t;
	int u, v;
};

EDGET edge[MAXM];
double map[MAXN][MAXN];
double dis[MAXN];
bool vis[MAXN];
int n, m, f;

double prim()
{
	double ret=0;
	for (int i=1; i<=n; i++) dis[i]=inf;
	dis[1]=0;
	memset(vis, 0, sizeof(vis));
	while (1)
	{
		double min=inf;
		int k=-1;
		for (int i=1; i<=n; i++)
			if (!vis[i]&&dis[i]<min)
			{
				min=dis[i];
				k=i;
			}
		if (k==-1) break;
		vis[k]=true;
		ret+=min;
		for (int i=1; i<=n; i++)
			if (!vis[i]&&dis[i]>map[k][i])
				dis[i]=map[k][i];
	}
	for (int i=1; i<=n; i++)
		if (!vis[i]) return inf;
	return ret;
}

void build(double mid)
{
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
			map[i][j]=map[j][i]=inf;
		map[i][i]=0;
	}
	for (int i=1; i<=m; i++)
		if (map[edge[i].u][edge[i].v]>(double)edge[i].c+edge[i].t*mid)
		{
			map[edge[i].u][edge[i].v]=(double)edge[i].c+edge[i].t*mid;
			map[edge[i].v][edge[i].u]=(double)edge[i].c+edge[i].t*mid;
		}
}

int main()
{
	freopen("quake.in", "r", stdin);
	freopen("quake.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &f);
	for (int i=1; i<=m; i++)
		scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].c, &edge[i].t);
	double left=0, right=f;
	while (fabs(left-right)>eps)
	{
		double mid=(left+right)/2.0;
		build(mid);
		double tmp=prim();
		if (tmp<f) left=mid;
		else right=mid;
	}
	printf("%.4f\n", right);
	fclose(stdin); fclose(stdout);
}
