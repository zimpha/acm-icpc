#include <cstdio>
#include <cstring>

const int MAXN=100;

int score[MAXN];
int rank[MAXN];
int n, m, p;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d%d%d", &m, &n, &p);
		for (int i=1; i<=m; i++)
			scanf("%d", score+i);
		rank[1]=1;
		for (int i=2; i<=m; i++)
			if (score[i]!=score[i-1]) rank[i]=i;
			else rank[i]=rank[i-1];
		int ret=-1;
		for (int i=1; i<=m; i++)
			if (score[i]<n)
			{
				ret=i;
				break;
			}
		if (ret==-1)
		{
			if (score[m]==n)
			{
				if (m<p) printf("%d\n", rank[m]);
				else printf("-1\n");
			}
			else 
			{
				if (m<p) printf("%d\n", m+1);
				else printf("-1\n");
			}
		}
		else
		{
			if (score[ret-1]==n) printf("%d\n", rank[ret-1]);
			else printf("%d\n", rank[ret]);
		}
	}
	return 0;
}
