#include <cstdio>
#include <cstring>

const int MAXN=105;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int now[MAXN][MAXN];
int tmp[MAXN][MAXN];
int r, c, n;

void expand(int x, int y, int xx, int yy)
{
	if (xx<1|xx>r||yy<1||yy>c) return;
	if ((now[x][y]+1)%3==now[xx][yy]) 
		tmp[xx][yy]=now[x][y];
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d%d", &r, &c, &n);
		for (int i=1; i<=r; i++)
		{
			getchar();
			for (int j=1; j<=c; j++)
			{
				char ch=getchar();
				if (ch=='R') now[i][j]=0;
				if (ch=='S') now[i][j]=1;
				if (ch=='P') now[i][j]=2;
			}
		}
		while (n--)
		{
			memcpy(tmp,now,sizeof(now));
			for (int i=1; i<=r; i++)
				for (int j=1; j<=c; j++)
					for (int k=0; k<4; k++)
						expand(i,j,i+dx[k],j+dy[k]);
			memcpy(now,tmp,sizeof(tmp));
		}
		for (int i=1; i<=r; i++)
		{
			for (int j=1; j<=c; j++)
			{
				if (now[i][j]==0) putchar('R');
				if (now[i][j]==1) putchar('S');
				if (now[i][j]==2) putchar('P');
			}
			puts("");
		}
		if (test) puts("");
	}
	return 0;
}
