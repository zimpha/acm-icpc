#include <cstdio>
#include <cstring>

const int MAXN=105;

int matrix[MAXN][MAXN];
int n,m;

int main()
{
    int cas=0;
    while (scanf("%d",&m)==1)
    {
	memset(matrix,0,sizeof(matrix));
	n=0;
	while (m--)
	{
	    int u,v;
	    scanf("%d%d",&u,&v);
	    matrix[u][v]=1;
	    if (u+1>n) n=u+1;
	    if (v+1>n) n=v+1;
	}
	for (int k=0; k<n; k++)
	    for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
		    matrix[i][j]+=matrix[i][k]*matrix[k][j];
	for (int k=0; k<n; k++)
	    if (matrix[k][k])
	    {
		matrix[k][k]=-1;
		for (int i=0; i<n; i++)
		    for (int j=0; j<n; j++)
			if (matrix[i][k]&&matrix[k][j])
			    matrix[i][j]=-1;
	    }
	printf("matrix for city %d\n",cas++);
	for (int i=0; i<n; i++)
	    for (int j=0; j<n; j++)
		printf("%d%c",matrix[i][j],(j==n-1)?'\n':' ');
    }
    return 0;
}
