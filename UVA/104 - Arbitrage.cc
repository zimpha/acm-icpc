#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=25;
const int inf=1e8;

double g[MAXN][MAXN][MAXN];
int path[MAXN][MAXN][MAXN];
int ans[MAXN];
int n;

bool floyd()
{
    for (int step=2; step<=n; step++)
    {
	for (int k=1; k<=n; k++)
	    for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
		    if (g[i][j][step]<g[i][k][step-1]*g[k][j][1])
		    {
			g[i][j][step]=g[i][k][step-1]*g[k][j][1];
			path[i][j][step]=k;
			if (g[i][j][step]>1.01&&i==j)
			{
			    ans[0]=step+1;
			    ans[step+1]=i;
			    while (step)
			    {	
				ans[step]=path[i][j][step];
				j=path[i][j][step];
				step--;
			    }
			    return true;
			}
		    }
    }
    return false;
}

int main()
{
    while (scanf("%d",&n)==1)
    {
	memset(path,-1,sizeof(path));
	memset(g,0,sizeof(g));
	for (int i=1; i<=n; i++)
	    for (int j=1; j<=n; j++)
	    {
		if (i!=j) scanf("%lf",&g[i][j][1]);
		else g[i][j][1]=1;
		path[i][j][1]=i;
	    }
	if (floyd())
	{
	    for (int i=1; i<=ans[0]; i++)
		printf("%d%c",ans[i],(i==ans[0])?'\n':' ');
	}
	else printf("no arbitrage sequence exists\n");
    }
    return 0;
}
