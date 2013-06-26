#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=60;

char map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dice[MAXN][MAXN];
int dots[MAXN*MAXN];
int n,m,sum;

void fill1(int x, int y)
{
    dice[x][y]=sum;
    if (x>1&&(map[x-1][y]=='*'||map[x-1][y]=='X')&&!dice[x-1][y]) fill1(x-1,y);
    if (x<n&&(map[x+1][y]=='*'||map[x+1][y]=='X')&&!dice[x+1][y]) fill1(x+1,y);
    if (y>1&&(map[x][y-1]=='*'||map[x][y-1]=='X')&&!dice[x][y-1]) fill1(x,y-1);
    if (y<m&&(map[x][y+1]=='*'||map[x][y+1]=='X')&&!dice[x][y+1]) fill1(x,y+1);
}

void fill2(int x,int y)
{
    vis[x][y]=true;
    if (x>1&&map[x-1][y]=='X'&&!vis[x-1][y]) fill2(x-1,y);
    if (x<n&&map[x+1][y]=='X'&&!vis[x+1][y]) fill2(x+1,y);
    if (y>1&&map[x][y-1]=='X'&&!vis[x][y-1]) fill2(x,y-1);
    if (y<m&&map[x][y+1]=='X'&&!vis[x][y+1]) fill2(x,y+1);
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&m,&n)==2&&n)
    {
	for (int i=1; i<=n; i++)
	{
	    getchar();
	    for (int j=1; j<=m; j++)
		map[i][j]=getchar();
	}
	sum=0;
	memset(dice,0,sizeof(dice));
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=m; j++)
		if (!dice[i][j]&&(map[i][j]=='*'||map[i][j]=='X'))
		{
		    sum++;
		    fill1(i,j);
		}
	memset(dots,0,sizeof(dots));
	memset(vis,0,sizeof(vis));
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=m; j++)
		if (!vis[i][j]&&map[i][j]=='X')
		{
		    dots[dice[i][j]]++;
		    fill2(i,j);
		}
	std::sort(dots+1,dots+sum+1);
	printf("Throw %d\n",++cas);
	for (int i=1; i<=sum; i++)
	    printf("%d%c",dots[i],(i==sum)?'\n':' ');
	printf("\n");
    }
    return 0;
}
