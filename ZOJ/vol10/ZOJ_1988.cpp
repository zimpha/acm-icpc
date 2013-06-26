#include <cstdio>
#include <cstring>

const int MAXN=55;
const int SIZE=1005;

struct node
{
	int l;
	int a[SIZE];
};

bool vis[MAXN][MAXN];
node dp[MAXN][MAXN];
int n,m;

node mul(node a, int n)
{
	int x=0;
	for (int i=0; i<a.l; i++)
	{
		a.a[i]=a.a[i]*n+x;
		x=a.a[i]/10;
		a.a[i]%=10;
	}
	while (x)
	{
		a.a[a.l++]=x%10;
		x/=10;
	}
	return a;
}

node add(node a, node b)
{
	int x=0;
	node c;
	memset(c.a,0,sizeof(c.a));
	for (int i=0; i<a.l||i<b.l; i++)
	{
		c.a[i]=a.a[i]+b.a[i]+x;
		x=c.a[i]/10;
		c.a[i]%=10;
	}
	c.l=((a.l>b.l)?a.l:b.l);
	if (x>0) c.a[c.l++]=x;
	return c;
}

void calc(int n, int m)
{
	if (vis[n][m]) return;
	vis[n][m]=true;
	if (n==1&&m==1)
	{
		dp[n][m].l=1;
		dp[n][m].a[0]=1;
		return;
	}
	if (m>n||m==0||n==0)
	{
		dp[n][m].l=1;
		dp[n][m].a[0]=0;
		return;
	}
	node ret;
	calc(n-1,m); dp[n][m]=mul(dp[n-1][m],m);
	calc(n-1,m-1); ret=mul(dp[n-1][m-1],2*n-m);
	dp[n][m]=add(ret,dp[n][m]);
}

int main()
{
	int test;
	scanf("%d", &test);
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	while (test--)
	{
		scanf("%d%d", &n, &m);
		calc(n,m);
		for (int i=dp[n][m].l-1; i>=0; i--)
			printf("%d", dp[n][m].a[i]);
		printf("\n");
	}
	return 0;
}
