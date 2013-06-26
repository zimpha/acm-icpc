#include <cstdio>
#include <cstring>

const int MAXN=500005;

bool vis[MAXN];
int pre[MAXN];
int ret[MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=2; i<=n; i++)
			scanf("%d", pre+i);
		memset(vis, 0, sizeof(vis));
		int ans=0;
		for (int i=n; i>1; i--)
			if (!vis[pre[i]]&&!vis[i])
			{
				ret[++ans]=i;
				vis[pre[i]]=true;
			}
			else vis[i]=true;
		printf("%d000\n", ans);
		for (int i=ans; i>0; i--)
			printf("%d%c", ret[i], (i==1)?'\n':' ');
		if (test) puts("");
	}
	return 0;
}
