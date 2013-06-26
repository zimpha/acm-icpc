#include <cstdio>
#include <cstring>

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int now[20][20], tmp[20][20];
int d[16];
int n;

int calc(int x, int y)
{
	int res=tmp[x][y];
	for (int i=0; i<4; i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if (xx<0||xx>19||yy<0||yy>19) continue;
		res+=tmp[xx][yy];
	}
	return res;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<16; i++)
			scanf("%d", d+i);
		for (int i=0; i<20; i++)
			for (int j=0; j<20; j++)
				scanf("%d", &now[i][j]);
		while (n--)
		{
			memcpy(tmp,now,sizeof(now));
			for (int i=0; i<20; i++)
				for (int j=0; j<20; j++)
				{
					now[i][j]=tmp[i][j]+d[calc(i,j)];
					if (now[i][j]>3) now[i][j]=3;
					if (now[i][j]<0) now[i][j]=0;
				}
		}
		for (int i=0; i<20; i++)
		{
			for (int j=0; j<20; j++)
				switch (now[i][j])
				{
					case 3: putchar('#'); break;
					case 2: putchar('X'); break;
					case 1: putchar('!'); break;
					default: putchar('.'); break;
				}
			puts("");
		}
		if (test) puts("");
	}
	return 0;
}
