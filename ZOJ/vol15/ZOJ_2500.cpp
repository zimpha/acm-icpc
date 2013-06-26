#include <cstdio>
#include <cstring>

const int MAXN=105;

bool map1[MAXN][MAXN];
bool map[MAXN][MAXN];
int deg[MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d", &n, &m);
		memset(map,0,sizeof(map));
		memset(map1,0,sizeof(map1));
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			map[a][b]=1;
			map1[b][a]=1;
		}
		for (int k=1; k<=n; k++)
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					map[i][j]|=map[i][k]&map[k][j];
		for (int k=1; k<=n; k++)
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					map1[i][j]|=map1[i][k]&map1[k][j];
		int ret=0;
		for (int i=1; i<=n; i++)
		{
			deg[i]=0;
			for (int j=1; j<=n; j++)
				if (map[i][j]) deg[i]++;
			if (deg[i]>n/2) ret++;
		}
		for (int i=1; i<=n; i++)
		{
			deg[i]=0;
			for (int j=1; j<=n; j++)
				if (map1[i][j]) deg[i]++;
			if (deg[i]>n/2) ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
