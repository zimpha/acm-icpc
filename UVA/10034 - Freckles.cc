#include <cstdio>
#include <cmath>
#include <cstring>

const int MAXN=105;
const int inf=100000000;

double x[MAXN],y[MAXN];
double dis[MAXN];
bool vis[MAXN];
int n;

double dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

double prim()
{
    for (int i=1; i<=n; i++)
    {
	dis[i]=inf;
	vis[i]=0;
    }
    double ans=0; dis[1]=0;
    while (1)
    {
	double min=inf;
	int u;
	for (int i=1; i<=n; i++)
	    if (!vis[i]&&dis[i]<min)
	    {
		min=dis[i];
		u=i;
	    }
	if (min==inf) break;
	ans+=min; vis[u]=1;
	for (int v=1; v<=n; v++)
	    if (!vis[v]&&dis[v]>dist(u,v))
		dis[v]=dist(u,v);
    }
    return ans;
}

int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	    scanf("%lf%lf",x+i,y+i);
	printf("%.2f\n",prim());
	if (test) putchar('\n');
    }
    return 0;
}
