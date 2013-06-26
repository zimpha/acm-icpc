#include <cstdio>

bool oil[101][101];
int f[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int n,m;

int DFS(int i,int j)
{
	int x,y,d;
	oil[i][j]=0;
	for(d=0;d<8;d++)
	{
		x=i+f[d][0];
		y=j+f[d][1];
		if(x>0&&y>0&&x<=m&&y<=n&&oil[x][y])
		    DFS(x,y);
	}
    return 0;
}

int main()
{
    char c;
	int i,j,ans;
	while(scanf("%d%d\n",&m,&n)!=EOF&&m)
	{
		ans=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&c);
				oil[i][j]=(c=='@'?1:0);
			}
			getchar();
		}
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
				if(oil[i][j])
				   DFS(i,j), ans++;
       printf("%d\n",ans);
	}
	return 0;
}

