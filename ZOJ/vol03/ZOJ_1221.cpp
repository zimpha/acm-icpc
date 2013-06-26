#include <cstdio>
#include <cstring>

const int N=21;
const int inf=100000;

int g[N][N];

int main()
{
    int cas=0,n;
    while (scanf("%d",&n)==1)
    {
	for (int i=1; i<N; i++)
	    for (int j=1; j<N; j++)
		g[i][j]=(i==j)?0:inf;
	int x;
	for (int i=0; i<n; i++)
	{
	    scanf("%d",&x);
	    g[1][x]=g[x][1]=1;
	}
	for (int i=2; i<20; i++)
	{
	    scanf("%d",&n);
	    for (int j=0; j<n; j++)
	    {
		scanf("%d",&x);
		g[i][x]=g[x][i]=1;
	    }
	}
	for (int k=1; k<N; k++)
	    for (int i=1; i<N; i++)
		for (int j=1; j<N; j++)
		    if (g[i][j]>g[i][k]+g[k][j])
			g[i][j]=g[i][k]+g[k][j];
	printf("Test Set #%d\n",++cas);
	scanf("%d",&n);
	while (n--)
	{
	    int a,b;
	    scanf("%d%d",&a,&b);
	    printf("%d to %d: %d\n",a,b,g[a][b]);
	}
	printf("\n");
    }
    return 0;
}
