#include <cstdio>
#include <cstring>

const int MAXN=13;
const int MAXM=6;

int s[MAXN], a[MAXM];
int n, m;

int out()
{
	printf("%d", a[0]);
	for (int i=1; i<m; i++)
		printf(" %d", a[i]);
	puts("");
}

void dfs(int dep, int cur)
{
	if (dep==m)
	{
		out();
		return;
	}
	for (int i=cur; i<n; i++)
	{
		a[dep]=s[i];
		dfs(dep+1,i+1);
	}
}

int main()
{
	int cas=0;
	m=6;
	while (scanf("%d", &n)==1&&n)
	{
		for (int i=0; i<n; i++)
			scanf("%d", s+i);
		if (cas) puts("");
		dfs(0,0);
		cas++;
	}
}
