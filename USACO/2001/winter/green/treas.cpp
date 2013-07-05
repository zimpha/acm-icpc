#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN=82;
const int SIZE=80*80*5;
const int MAXT=1000000;

short x[MAXN], y[MAXN], z[MAXN], V[MAXN];
short dis[MAXN][MAXN];
int dp[MAXN][SIZE];
int time[SIZE];
int hash[MAXT];
int N, T, M;

int main()
{
	freopen("treas.in", "r", stdin);
	freopen("treas.out", "w", stdout);
	scanf("%d%d", &N, &T);
	N++;
	x[0]=y[0]=z[0]=V[0]=0;
	x[N]=y[N]=z[N]=V[N]=0;
	for (int i=1; i<N; i++)
	{
		scanf("%d%d%d%d", x+i, y+i, z+i, V+i);
		z[i]*=2;
	}
	for (int i=0; i<N; i++)
		for (int j=i+1; j<=N; j++)
			dis[i][j]=dis[j][i]=abs(x[i]-x[j])+abs(y[i]-y[j]);
	memset(dp, -1, sizeof(dp));
	memset(hash, -1, sizeof(hash));
	hash[0]=time[0]=dp[0][0]=0;
	M=1;
	for (int i=1; i<=N; i++)
	{
		for (int j=0; j<i; j++)
		{
			for (int k=0; k<M; k++)
			{
				if (dp[j][k]==-1) continue;
				int sum=time[k]+dis[i][j]+z[i];
				if (sum>T) continue;
				if (hash[sum]==-1)
				{
					hash[sum]=M;
					time[M]=sum;
					M++;
				}
				int tmp=hash[sum];
				if (dp[i][tmp]==-1||(dp[i][tmp]<dp[j][k]+V[i]))
					dp[i][tmp]=dp[j][k]+V[i];
			}
		}
	}
	int ans=0;
	for (int i=T; i>=0; i--)
		if (hash[i]!=-1&&dp[N][hash[i]]>ans)
			ans=dp[N][hash[i]];
	printf("%d\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
