#include <cstdio>
#include <cstring>

const int MAXN=105;

int S[MAXN][MAXN];
int w, h, n, s, t;

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		scanf("%d%d", &w, &h);
		memset(S,0,sizeof(S));
		while (n--)
		{
			int x, y;
			scanf("%d%d", &y, &x);
			S[x][y]=1;
		}
		for (int i=1; i<=h; i++)
			for (int j=1; j<=w; j++)
				S[i][j]+=S[i][j-1];
		for (int i=1; i<=h; i++)
			for (int j=1; j<=w; j++)
				S[i][j]+=S[i-1][j];
		scanf("%d%d", &s, &t);
		int ret=0;
		for (int i=t; i<=h; i++)
			for (int j=s; j<=w; j++)
			{
				int tmp=S[i][j]+S[i-t][j-s]-S[i][j-s]-S[i-t][j];
				if (tmp>ret) ret=tmp;
			}
		printf("%d\n", ret);
	}
	return 0;
}
