#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=105;
const int MAXF=205;
const int MAXK=505;

typedef struct point{int x, y;}point;
typedef struct fence{point a, b; int h;}fence;

double dis[MAXK][MAXN];
double map[MAXN][MAXN];
point cow[MAXN];
fence fen[MAXF];
point barn;
int n, f, k;

void init()
{
	scanf("%d%d%d%d%d", &n, &k, &f, &cow[0].x, &cow[0].y);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &cow[i].x, &cow[i].y);
	for (int i=0; i<f; i++)
		scanf("%d%d%d%d%d", &fen[i].a.x, &fen[i].a.y, &fen[i].b.x, &fen[i].b.y, &fen[i].h);
}

int cross(point a, point b, point c)
{
	double tmp=(double)(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	if (tmp>0) return 1;
	if (tmp==0) return 0;
	else return -1;
}

bool check(point a, point b, point c, point d)
{
	int tmp1=cross(a, b, d)*cross(a, b, c);
	int tmp2=cross(c, d, a)*cross(c, d, b);
	if (tmp1<0&&tmp2<0) return true;
	else return false;
}

void build()
{
	for (int i=0; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			map[i][j]=1;
			for (int l=0; l<f; l++)
				if (check(cow[i], cow[j], fen[l].a, fen[l].b))
					map[i][j]*=(double)1/fen[l].h;
			map[j][i]=map[i][j];
		}
		map[i][i]=1;
	}
	for (int l=0; l<=n; l++)
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				if (map[i][j]<map[i][l]*map[l][j])
					map[i][j]=map[i][l]*map[l][j];
}

void print(double x)
{
	int b=0;
	while (x<1)
	{
		b++;
		x*=10;
	}
	if (b==0) printf("1.0000e00");
	else if (b<10) printf("%.4fe-0%d\n", x, b);
	else printf("%.4fe-%d\n", x, b);
}

void solve()
{
	for (int i=1; i<=n; i++)
		dis[1][i]=map[0][i];
	for (int l=2; l<=k; l++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if (i!=j&&dis[l][i]<dis[l-1][j]*map[j][i])
					dis[l][i]=dis[l-1][j]*map[j][i];
	double ans=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=k; j++)
			if (ans<dis[j][i]*dis[k+1-j][i])
				ans=dis[j][i]*dis[k+1-j][i];
	print(ans);
}

int main()
{
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
	init();
	build();
	solve();
	fclose(stdin); fclose(stdout);
	return 0;
}
