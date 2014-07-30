#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;

struct node
{
	int id, w, s;
};

int dp[MAXN], p[MAXN];
node mice[MAXN];

bool cmp(node a, node b)
{
	if (a.w==b.w) return (a.s>b.s);
	else return (a.w<b.w);
}

int main()
{
	int n=0, m=0;
	while (scanf("%d%d", &mice[n].w, &mice[n].s)==2)
	{
		mice[n].id=n+1;
		n++;
	}
	std::sort(mice,mice+n,cmp);
	for (int i=n-1; i>=0; i--)
	{
		dp[i]=1; p[i]=-1;
		for (int j=i+1; j<n; j++)
			if (mice[i].w<mice[j].w&&mice[i].s>mice[j].s&&dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				p[i]=j;
			}
		if (dp[i]>m) m=dp[i];
	}
	for (int i=0; i<n; i++)
		if (dp[i]==m)
		{
			printf("%d\n%d\n", m, mice[i].id);
			while (p[i]!=-1)
			{
				i=p[i];
				printf("%d\n", mice[i].id);
			}
			break;
		}
	return 0;
}
