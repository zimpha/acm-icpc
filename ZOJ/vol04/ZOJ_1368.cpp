#include <cstdio>
#include <cstring>
#include <algorithm>

using std::max;

const int MAXN=105;
const int MAXD=105;

int f[MAXN][MAXD];
int w[MAXN][MAXD];
int last[MAXN];
int n,m;

int main()
{
	int cas=0;
	while (scanf("%d", &n)==1)
	{
		if (cas++) printf("\n");
		for (int i=1; i<=n; i++)
			scanf("%d", last+i);
		memset(w,0,sizeof(w));
		scanf("%d", &m);
		while (m--)
		{
			int id, deadline, money;
			scanf("%d%d%d", &id, &deadline, &money);
			for (int i=0; i<=deadline-last[id]+1; i++)
				if (w[id][i]<money) w[id][i]=money;
		}
		m=100;
		int ret=0;
		memset(f,0,sizeof(f));
		for (int i=1; i<=n; i++)
			for (int j=0; j<=m; j++)
			{
				if (j>0) f[i][j]=f[i][j-1];
				for (int k=0; k<=j; k++)
				{
					if (k+last[i]<=j) f[i][j]=max(f[i][j],f[i-1][k]+w[i][k+1]);
					else f[i][j]=max(f[i][j],f[i-1][k]);
				}
				ret=max(ret,f[i][j]);
			}
		printf("%d\n", ret);
	}
	return 0;
}
