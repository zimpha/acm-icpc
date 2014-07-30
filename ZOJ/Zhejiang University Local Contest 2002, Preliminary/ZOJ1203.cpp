#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=105;
const int inf=1000000000;

double x[MAXN], y[MAXN];
double map[MAXN][MAXN];
double dis[MAXN];
bool vis[MAXN];
int N;

double dist(double x1, double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double prim()
{
	for (int i=0; i<N; i++)
		dis[i]=inf, vis[i]=false;
	dis[0]=0;
	double ret=0;
	for (int i=0; i<N; i++)
	{
		int k=-1;
		for (int j=0; j<N; j++)
			if (!vis[j]&&(k==-1||dis[k]>dis[j])) k=j;
		if (k==-1) break;
		ret+=dis[k]; vis[k]=true;
		for (int j=0; j<N; j++)
			if (!vis[j]&&dis[j]>map[k][j]) dis[j]=map[k][j];
	}
	return ret;
}

int main()
{
	int cas=0;
	cout.precision(2);
	while ((cin >> N)&&N)
	{
		if (cas) puts("");
		for (int i=0; i<N; i++)
		{
			cin >> x[i] >> y[i];
			for (int j=0; j<i; j++)
				map[i][j]=map[j][i]=dist(x[i], y[i], x[j], y[j]);
		}
		cout << "Case #" << ++cas << ":" << endl;
		cout << "The minimal distance is: " << fixed << prim() << endl;
	}
	return 0;
}
