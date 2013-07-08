#include <cstdio>
#include <cstring>

const int MAXN=1005;

bool vis[MAXN];
int F[MAXN];
int N;

int main()
{
	freopen("relay.in", "r", stdin);
	freopen("relay.out", "w", stdout);
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", F+i);
	int ret=0;
	for (int i=1; i<=N; i++)
	{
		memset(vis, 0, sizeof(vis));
		bool flag=true;
		for (int j=i; F[j]!=0&&flag; )
		{
			vis[j]=true;
			j=F[j];
			if (vis[j]) flag=false;
		}
		if (flag) ret++;
	}
	printf("%d\n", ret);
	fclose(stdin); fclose(stdout);
	return 0;
}
