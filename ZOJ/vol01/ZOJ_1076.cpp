#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=1005;

struct node
{
	int id, l, r;
};

node gene[MAXN];
int dp[MAXN], p[MAXN];
int ans[MAXN];
int n, m;

bool cmp(node a, node b)
{
	if (a.l==b.l) return (a.r<b.r);
	else return (a.l<b.l);
}

int main()
{
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=0; i<n; i++)
		{
			gene[i].id=i+1;
			scanf("%d%d", &gene[i].l, &gene[i].r);
		}
		std::sort(gene, gene+n, cmp);
		m=0;
		for (int i=0; i<n; i++)
		{
			dp[i]=1; p[i]=-1;
			for (int j=0; j<i; j++)
				if (gene[i].l>gene[j].r&&dp[i]<dp[j]+1)
				{
					dp[i]=dp[j]+1;
					p[i]=j;
				}
			if (dp[i]>m) m=dp[i];
		}
		for (int i=0; i<n; i++)
			if (dp[i]==m)
			{
				int j=m;
				ans[--j]=gene[i].id;
				while (p[i]!=-1)
				{
					i=p[i];
					ans[--j]=gene[i].id;
				}
				break;
			}
		for (int i=0; i<m; i++)
			printf("%d%c", ans[i], (i==m-1)?'\n':' ');
	}
	return 0;
}
