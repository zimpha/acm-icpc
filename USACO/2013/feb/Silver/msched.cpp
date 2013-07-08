#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN=10005;

struct EDGE
{
	int v;
	EDGE *next;
};

EDGE *head[MAXN];
queue<int> q;
int deg[MAXN];
long long dp[MAXN];
long long T[MAXN];
int N, M;

void solve()
{
	long long ans=0;
	while (!q.empty()) q.pop();
	memset(dp, 0, sizeof(dp));
	for (int i=1; i<=N; i++)
		if (!deg[i]) 
		{
			q.push(i);
			ans=max(ans, dp[i]=T[i]);
		}
	while (!q.empty())
	{
		int u=q.front(); q.pop();
		for (EDGE *p=head[u]; p; p=p->next)
		{
			int v=p->v;
			if (dp[v]<dp[u]+T[v]) 
				dp[v]=dp[u]+T[v];
			deg[v]--;
			if (deg[v]==0) q.push(v);
			ans=max(ans, dp[v]);
		}
	}
	printf("%lld\n", ans);
}

void addedge(int u, int v)
{
	EDGE *p=new(EDGE);
	p->v=v; p->next=head[u]; head[u]=p;
}

int main()
{
	freopen("msched.in", "r", stdin);
	freopen("msched.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		scanf("%lld", T+i);
	memset(head, 0, sizeof(head));
	memset(deg, 0, sizeof(deg));
	while (M--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
		deg[b]++;
	}
	solve();
	fclose(stdin); fclose(stdout);
}
