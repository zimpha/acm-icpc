#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=10005;
const int inf=100000000;

int cost[1000];
int dp[MAXN][10][10];
int N, M;

void print()
{
	int score=-inf, x=0, y=0;
	for (int i=0; i<10; i++)
		for (int j=0; j<10; j++)
		{
			if (score>=dp[N][i][j]) continue;
			score=dp[N][i][j]; x=i; y=j;
		}
	for (int i=N; i>=3; i--)
		for (int z=0; z<10; z++)
			if (dp[i-1][y][z]+cost[x*100+y*10+z]==score)
			{
				score-=cost[x*100+y*10+z];
				cout << x;
				x=y; y=z;
				break;
			}
	cout << x << y << endl;
}

int main()
{
	while (scanf("%d%d", &M, &N)==2)
	{
		if (N==1) {puts("0"); continue;}
		memset(dp, 0, sizeof(dp));
		memset(cost, 0, sizeof(cost));
		for (int x, y, i=0; i<M; i++)
		{
			scanf("%d%d", &x, &y);
			cost[x]=y;
		}
		for (int i=3; i<=N; i++)
			for (int x=0; x<10; x++)
				for (int y=0; y<10; y++)
				{
					dp[i][x][y]=-inf;
					for (int z=0; z<10; z++)
						dp[i][x][y]=max(dp[i][x][y], dp[i-1][y][z]+cost[x*100+y*10+z]);
				}
		print();
	}
	return 0;
}
