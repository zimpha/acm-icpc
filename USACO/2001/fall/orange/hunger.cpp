#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=1005;

struct node
{
	int l, r;
};

node seg[MAXN];
int dp[MAXN];
int n;

bool cmp(node a, node b)
{
	if (a.l==b.l) return (a.r<b.r);
	else return (a.l<b.l);
}

int main()
{
	freopen("hunger.in", "r", stdin);
	freopen("hunger.out", "w", stdout);
	memset(dp, 0, sizeof(dp));
	memset(seg, 0, sizeof(seg));
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d%d", &seg[i].l, &seg[i].r);
	sort(seg+1, seg+1+n, cmp);
	int ret=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<i; j++)
			if (seg[j].r<seg[i].l)
				dp[i]=max(dp[i], dp[j]+seg[i].r-seg[i].l+1);
		ret=max(ret, dp[i]);
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
}
