#include <cstdio>
#include <cstring>

const int MAXN=100000;

double dp[MAXN];
int n;

int main()
{
	dp[0]=0;
	for (int i=1; i<MAXN; i++)
		dp[i]=dp[i-1]+1.0/(2.0*i);
	printf("# Cards  Overhang\n");
	while (scanf("%d", &n)==1)
	{
		printf("%5d     %.3f\n", n, dp[n]);
	}
	return 0;
}
