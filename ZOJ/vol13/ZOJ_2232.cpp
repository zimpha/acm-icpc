#include <cmath>
#include <cstdio>
#include <cstring>

const int MAXN=5005;
const int MAXM=1000005;
const int inf=100000000;

int dp[MAXM];
int x[MAXN];
int y[MAXN];
int n, m;

int calc(int h)
{
	double t1=h;
	double t2=h-y[0];
	return (int)sqrt(t1*t1-t2*t2);
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d%d", x+i, y+i);
		m=x[n-1];
		for (int i=0; i<=m; i++)
			dp[i]=inf;
		dp[x[0]]=0;
		int ret=inf;
		for (int i=1; i<n; i++)
		{
			int delta=calc(y[i]);
			int st=x[i]-delta;
			if (st<x[0]) st=x[0];
			for (int j=st; j<x[i]; j++)
			{
				int tmp=2*x[i]-j;
				if (tmp<m&&dp[tmp]>dp[j]+1) dp[tmp]=dp[j]+1;
				if (tmp>=m&&dp[j]+1<ret) ret=dp[j]+1;
			}
		}
		if (ret==inf) ret=-1;
		printf("%d\n", ret);
	}
	return 0;
}

