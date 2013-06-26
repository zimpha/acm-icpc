#include <cstdio>
#include <cstring>

const int MAXN=55;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};

char map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, sum;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%s", map[i]);
		m=strlen(map[0]);
		sum=0;
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				sum+=map[i][j]-'0';
		memset(vis,0,sizeof(vis));
		int count=n*m-1;
		int x=0, y=0, d=0;
		while (count--)
		{
			vis[x][y]=true;
			if (x+dx[d]<0||x+dx[d]==n||y+dy[d]<0||y+dy[d]==m||vis[x+dx[d]][y+dy[d]])
			{
				d=(d+1)%4;
				sum-=map[x][y]-'0';
			}
			x+=dx[d];
			y+=dy[d];
		}
		printf("%d\n", sum);
	}
	return 0;
}
