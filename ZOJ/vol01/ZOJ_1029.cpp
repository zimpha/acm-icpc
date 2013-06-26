#include <cstdio>
#include <cstring>
#include <algorithm>

using std::swap;

const int MAXN=205;

int times[MAXN];
int n;

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		memset(times,0,sizeof(times));
		while (n--)
		{
			int s, t;
			scanf("%d%d", &s, &t);
			if (t<s) swap(s,t);
			s=(s+1)/2; t=(t+1)/2;
			for (int i=s; i<=t; i++)
				times[i]++;
		}
		int ans=0;
		for (int i=1; i<=200; i++)
			if (ans<times[i]) ans=times[i];
		printf("%d\n", ans*10);
	}
	return 0;
}
