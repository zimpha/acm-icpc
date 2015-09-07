#include <cstdio>
#include <cstring>

const int MAXN=250;

bool map[MAXN][MAXN];
bool flag;
int n,m,cur;

void dfs(int x,int y)
{
    map[x][y]=0; cur++;
    if (x>1&&map[x-1][y]) dfs(x-1,y);
    else if (x==1) flag=false;
    if (x<n&&map[x+1][y]) dfs(x+1,y);
    else if (x==n) flag=false;
    if (y>1&&map[x][y-1]) dfs(x,y-1);
    else if (y==1) flag=false;
    if (y<m&&map[x][y+1]) dfs(x,y+1);
    else if (y==m) flag=false;
}

int main()
{
    int cas=0;
    while (scanf("%d%d",&m,&n)==2&&n)
    {
	memset(map,1,sizeof(map));
	for (int i=0; i<n; i++)
	{
	    getchar();
	    for (int j=0; j<m; j++)
	    {
		char c=getchar();
		if (c=='\\') map[3*i+1][3*j+1]=map[3*i+2][3*j+2]=map[3*i+3][3*j+3]=0;
		if (c=='/') map[3*i+1][3*j+3]=map[3*i+2][3*j+2]=map[3*i+3][3*j+1]=0;
	    }
	}
	n*=3; m*=3;
	int sum=0, ans=0;
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=m; j++)
		if (map[i][j])
		{
		    flag=true; cur=0;
		    dfs(i,j);
		    if (flag)
		    {
			sum++;
			if (cur>ans) ans=cur;
		    }
		}
	printf("Maze #%d:\n",++cas);
	if (sum) printf("%d Cycles; the longest has length %d.\n",sum,ans/3);
	else printf("There are no cycles.\n");
	printf("\n");
    }
    return 0;
}
