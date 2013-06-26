#include <cstdio>
#include <cstring>

const int MAXN=10;
const int inf=10000;

int pan[MAXN][MAXN];
int tmp[MAXN][MAXN];
int n, m;

void flip(int x, int y)
{
	for (int i=-1; i<=1; i++)
		for (int j=-1; j<=1; j++)
		{
			int xx=x+i;
			int yy=y+j;
			if (xx<0||xx>=n||yy<0||yy>=m) continue;
			tmp[xx][yy]^=1;
		}
}

int solve()
{
	int step=0;
	for (int i=1; i<n; i++)
		for (int j=1; j<m; j++)
			if (!tmp[i-1][j-1])
			{
				flip(i,j);
				step++;
			}
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (!tmp[i][j]) return inf;
	return step;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
		{
			char buff[MAXN];
			scanf("%s", buff);
			m=strlen(buff);
			for (int j=0; j<m; j++)
				if (buff[j]=='*') pan[i][j]=1;
				else pan[i][j]=0;
		}
		int state=1<<(n+m-1);
		int ret=inf;
		for (int s=0; s<state; s++)
		{
			memcpy(tmp,pan,sizeof(pan));
			int bit=1, step=0;
			for (int i=0; i<m; i++)
			{
				if (s&bit) 
				{
					flip(0,i);
					step++;
				}
				bit<<=1;
			}
			for (int i=1; i<n; i++)
			{
				if (s&bit)
				{
					flip(i,0);
					step++;
				}
				bit<<=1;
			}
			step+=solve();
			if (step<ret) ret=step;
		}
		if (ret<inf) printf("%d\n", ret);
		else printf("-1\n");
	}
	return 0;
}
