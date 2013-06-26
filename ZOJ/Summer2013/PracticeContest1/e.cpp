#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=55;

int can[MAXN];
int n;

bool cmp(int a, int b)
{
	return (a>b);
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		memset(can,0,sizeof(can));
		for (int i=0; i<n; i++)
			scanf("%d", can+i);
		int day=1;
		while (1)
		{
			bool flag=true;
			std::sort(can,can+n,cmp);
			for (int i=0; i<day; i++)
			{
				if (can[i]==0)
				{
					flag=false;
					break;
				}
				can[i]--;
			}
			if (!flag) break;
			day++;
		}
		printf("%d\n", day-1);
	}
	return 0;
}
