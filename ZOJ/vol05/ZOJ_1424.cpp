#include <cstdio>
#include <cstring>

const int MAXN=20;

struct node
{
	int ltx, lty;
	int rbx, rby;
	int c;
};

int map[MAXN][MAXN];
node rec[MAXN];
bool vis[MAXN];
int deg[MAXN];
int n, ans;

bool check(node a, node b)
{
	if (a.rby!=b.lty) return false;
	if (a.ltx<b.rbx&&a.rbx>b.ltx) return true;
	return false;
}

void dfs(int u, int step)
{
	if (step>=ans) return;
	for (int i=1; i<=map[u][0]; i++)
		deg[map[u][i]]--;
	bool flag=false;
	for (int i=1; i<=n; i++)
		if (!vis[i]&&deg[i]==0)
		{
			vis[i]=true;
			flag=true;
			if (rec[u].c==rec[i].c) dfs(i,step);
			else dfs(i,step+1);
			vis[i]=false;
		}
	for (int i=1; i<=map[u][0]; i++)
		deg[map[u][i]]++;
	if (!flag&&ans>step) ans=step;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=1; i<=n; i++)
			scanf("%d%d%d%d%d", &rec[i].lty, &rec[i].ltx, &rec[i].rby, &rec[i].rbx, &rec[i].c);
		memset(deg,0,sizeof(deg));
		memset(map,0,sizeof(map));
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if (check(rec[i],rec[j]))
				{
					map[i][0]++;
					map[i][map[i][0]]=j;
					deg[j]++;
				}
		ans=n+1;
		memset(vis,0,sizeof(vis));
		for (int i=1; i<=n; i++)
			if (deg[i]==0)
			{
				vis[i]=true;
				dfs(i,1);
				vis[i]=false;
			}
		printf("%d\n", ans);
	}
	return 0;
}

