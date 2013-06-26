#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN=55;

int num[MAXN], ans[MAXN];
int n, m;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%d", num+i);
		std::sort(num, num+n);
		bool flag=true;
		for (int i=1; i<n; i++)
			if (num[i]==num[i-1]||num[i]>num[i-1]+2)
			{
				flag=false;
				break;
			}
		if (flag)
		{
			int c=0;
			for (int i=1; i<n; i++)
				if (num[i]-num[i-1]==2) c++;
			if (c>1) flag=false;
		}
		if (flag)
		{
			int del=num[n-1]-num[0]+1;
			if (del==n)
			{
				if (num[0]!=1) printf("%d %d\n", num[0]-1, num[n-1]+1);
				else printf("%d\n", num[n-1]+1);
			}
			else if (del==n+1)
			{
				for (int i=1; i<n; i++)
					if (num[i]-num[i-1]==2)
					{
						printf("%d\n", num[i]-1);
						break;
					}
			}
		}
		else puts("");
	}
	return 0;
}
