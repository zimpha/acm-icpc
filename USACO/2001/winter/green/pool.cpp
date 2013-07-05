#include <cstdio>
#include <cstring>

const int SIZE=155;

typedef unsigned char byte;

short area[SIZE][SIZE][SIZE];
byte lmax[SIZE][SIZE][SIZE];
byte lmin[SIZE][SIZE][SIZE];
byte down[SIZE][SIZE];
byte up[SIZE][SIZE];
bool map[SIZE][SIZE];
int N, M, K;

int main()
{
	freopen("pool.in", "r", stdin);
	freopen("pool.out", "w", stdout);
	memset(map, 0, sizeof(map));
	scanf("%d%d%d", &M, &N, &K);
	while (K--)
	{
		int i, j;
		scanf("%d%d", &i, &j);
		map[i][j]=1;
	}
	
	for (int j=1; j<=M; j++)
		if (map[N][j]) down[N][j]=0;
		else down[N][j]=1;
	for (int i=N-1; i>0; i--)
		for (int j=1; j<=M; j++)
			if (map[i][j]) down[i][j]=0;
			else down[i][j]=down[i+1][j]+1;
	
	for (int j=1; j<=M; j++)
		if (map[1][j]) up[1][j]=0;
		else up[1][j]=1;
	for (int i=2; i<=N; i++)
		for (int j=1; j<=M; j++)
			if (map[i][j]) up[i][j]=0;
			else up[i][j]=up[i-1][j]+1;
	
	int min;
	memset(lmax, 0, sizeof(lmax));
	for (int i=N; i>0; i--)
		for (int j=M; j>0; j--)
		{
			if (map[i][j]) continue;
			lmax[i][j][j]=down[i][j];
			min=down[i][j];
			for (int k=j+1; k<=M; k++)
				if (map[i][k]) break;
				else
				{
					if (down[i][k]<min) min=down[i][k];
					lmax[i][j][k]=min;
				}
		}
	memset(lmin, 0, sizeof(lmin));
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
		{
			if (map[i][j]) continue;
			lmin[i][j][j]=up[i][j];
			min=up[i][j];
			for (int k=j+1; k<=M; k++)
				if (map[i][k]) break;
				else
				{
					if (up[i][k]<min) min=up[i][k];
					lmin[i][j][k]=min;
				}
		}
	
	int max;
	memset(area, 0, sizeof(area));
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
		{
			if (map[i][j]) continue;
			area[i][j][j]=lmin[i][j][j];
			for (int k=j+1; k<=M; k++)
			{
				max=area[i][j][k-1];
				if ((k-j+1)*lmin[i][j][k]>max)
					max=(k-j+1)*lmin[i][j][k];
				area[i][j][k]=max;
			}
		}
	int ret=0;
	for (int i=2; i<=N; i++)
		for (int j=1; j<=M; j++)
			if (map[i][j]==0&&map[i-1][j]==0)
			{
				for (int k=j+1; k<=M; k++)
					if (map[i][k]) break;
					else
					{
						max=lmax[i][j][k]*(k-j+1)+area[i-1][j][k-1];
						if (max>ret) ret=max;
					}
			}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
