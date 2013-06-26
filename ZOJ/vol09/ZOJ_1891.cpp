#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#define MAXN 1000

using namespace std;

double d[MAXN];
double g[MAXN][MAXN];
double x[MAXN],y[MAXN];
bool v[MAXN];
int l[MAXN];
int n, m;

double dis(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void Dijkstra()
{
	for (int i=1; i<=n; i++)
	{
		d[i]=1e10;
		v[i]=0;
	}
	d[1]=0;
	for (int i=1; i<n; i++)
	{
		int k;
		double min=1e10;
		for (int j=1; j<=n; j++)
			if (!v[j]&&d[j]<min)
			{
				min=d[j];
				k=j;
			}
		v[k]=1;
		for (int j=1; j<=n; j++)
			if (!v[j]&&d[j]>g[k][j]+d[k])
				d[j]=d[k]+g[k][j];
	}
}

int main()
{
	while ((cin >> x[1] >> y[1]))
	{
		cin >> x[2] >> y[2];
		l[0]=3; n=3; m=0;
		while ((cin >> x[n] >> y[n])&&x[n]!=-1)
		{
			n++;
			while ((cin >> x[n] >> y[n]))
			{
				if (x[n]==-1) break;
				else n++;
			}
			l[++m]=n;
		}
		n--;
		for (int i=1; i<=n; i++)
			for (int j=i+1; j<=n; j++)
				g[i][j]=g[j][i]=dis(i,j)/500*3;
		for (int i=0; i<m; i++)
			for (int j=l[i]; j<l[i+1]-1; j++)
				g[j+1][j]=g[j][j+1]=dis(j,j+1)/2000*3;

		Dijkstra();
		printf("%.0f\n",d[2]);
	}
	return 0;
}
