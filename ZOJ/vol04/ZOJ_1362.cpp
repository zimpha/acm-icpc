#include <cstdio>
#include <cstring>
#include <algorithm>

const int SIZE=1005;
const int MAXN=55;

bool have[SIZE];
int mine[MAXN];
int opp[MAXN];
int n, m;

int main()
{
	int cas=0;
	while (scanf("%d%d", &m, &n)==2&&m)
	{
		memset(have,0,sizeof(have));
		for (int i=0; i<n; i++)
		{
			scanf("%d", mine+i);
			have[mine[i]]=true;
		}
		std::sort(mine,mine+n);
		int sum=0;
		for (int i=n*m; i>0; i--)
			if (!have[i])
			{
				opp[sum++]=i;
				if (sum==n) break;
			}
		int ret=0, count=0;
		for (int i=sum-1; i>=0; i--)
		{
			if (opp[i]>mine[count])
			{
				ret++;
				count++;
			}
		}
		printf("Case %d: %d\n", ++cas, n-ret);
	}
	return 0;
}
