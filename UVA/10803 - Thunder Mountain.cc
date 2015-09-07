#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=105;
const int inf=1000000000;
const double eps=1e-8;

double g[MAXN][MAXN];
double x[MAXN];
double y[MAXN];
int n;

int sgn(double x)
{
    if (fabs(x)<=eps) return 0;
    else if (x<0) return -1;
    else return 1;
}

double dis(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
    int test,cas;
    scanf("%d",&test);
    for (int cas=1; cas<=test; cas++)
    {
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	    scanf("%lf%lf",x+i,y+i);
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=n; j++)
		g[i][j]=(i==j)?0:inf;
	for (int i=1; i<=n; i++)
	    for (int j=1; j<i; j++)
	    {
		double tmp=dis(i,j);
		if (sgn(10-tmp)>=0) g[i][j]=g[j][i]=tmp;
	    }
	for (int k=1; k<=n; k++)
	    for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		    if (g[i][j]>g[i][k]+g[k][j])
			g[i][j]=g[i][k]+g[k][j];
	double ans=0;
	for (int i=1; i<=n; i++)    
	    for (int j=1; j<=n; j++)
		if (g[i][j]>ans) ans=g[i][j];
	printf("Case #%d:\n",cas);
	if (ans<inf) printf("%.4lf\n\n",ans+1e-8);
	else printf("Send Kurdy\n\n");
    }
    return 0;
}
