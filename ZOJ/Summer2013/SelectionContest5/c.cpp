#include <cstdio>
#include <cstring>

const int MAXN=105;

int map[MAXN][MAXN];
int n;

int main()
{
	while (scanf("%d", &n)==1)
	{
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				scanf("%d", &map[i][j]);
		for (int k=1; k<=n; k++)
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					map[i][j]|=map[i][k]&map[k][j];
		int ret1=0, ret2=0;
		for (int i=1; i<=n; i++)
		{
			bool flag=true;
			for (int j=1; j<=n; j++)
				if (i!=j&&!map[i][j]) flag=false;
			if (flag) ret1++;
		}
		for (int i=1; i<=n; i++)
		{
			bool flag=true;
			for (int j=1; j<=n; j++)
				if (i!=j&&!map[j][i]) flag=false;
			if (flag) ret2++;
		}
		printf("%d, %d\n", ret1, ret2);
	}
	return 0;
}
