#include <cstdio>
#include <cstring>

const int MAXN=55;

typedef long long LL;

char map[MAXN][MAXN];
LL money[MAXN];
int deg[MAXN];
int que[MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		memset(deg,0,sizeof(deg));
		memset(money,0,sizeof(money));
		for (int i=1; i<=n; i++)
		{
			scanf("%s", map[i]+1);
			for (int j=1; j<=n; j++)
				if (map[i][j]=='Y')
					deg[i]++;
		}
		int head=1, tail=0;
		for (int i=1; i<=n; i++)
			if (deg[i]==0) 
			{
				que[++tail]=i;
				money[i]=1;
			}
		while (head<=tail)
		{
			int j=que[head]; head++;
			for (int i=1; i<=n; i++)
				if (map[i][j]=='Y')
				{
					deg[i]--;
					money[i]+=money[j];
					if (deg[i]==0) que[++tail]=i;
				}
		}
		LL sum=0;
		for (int i=1; i<=n; i++)
			sum+=money[i];
		printf("%lld\n", sum);
	}
	return 0;
}
