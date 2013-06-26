#include <cstdio>
#include <cstring>

const int MAXN=10;
const int MAXS=50000;
const int per[10]={0,1,2,6,24,120,720,5040,40320,362880};

double dp[MAXS];
int p[MAXN];
int n;

int getid(int p[])
{
	int res=0;
	for (int i=0; i<n; i++)
	{
		int count=0;
		for (int j=i+1; j<n; j++)
			if (p[i]>p[j]) count++;
		res+=count*per[n-i-1];
	}
	return res;
}

double solve(int p[])
{
	int id=getid(p);
	if (dp[id]!=-1) return dp[id];
	dp[id]=0;
	int tot=0, tmp;
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			if (p[i]>p[j])
			{
				tmp=p[i]; p[i]=p[j]; p[j]=tmp;
				dp[id]+=solve(p);
				tot++;
				tmp=p[i]; p[i]=p[j]; p[j]=tmp;
			}
	if (tot==0) dp[id]=0;
	else dp[id]=dp[id]/tot+1;
	return dp[id];
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d", p+i);
		for (int i=0; i<per[n]; i++) 
			dp[i]=-1;
		printf("%.5f\n", solve(p));
	}
	return 0;
}
