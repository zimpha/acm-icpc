#include <cstdio>
#include <cstring>

const int MAXN=2005;

char num[MAXN];
int ans[MAXN];
int n;

void dec(int o)
{
	ans[n]-=o;
	int i=n;
	while (ans[i]<0)
	{
		ans[i-1]-=1;
		ans[i]+=10;
		i--;
	}
	while (!ans[ans[0]]) ans[0]++;
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%s", num);
		n=strlen(num);
		if (n==1)
		{
			int m=num[0]-'0';
			if (m&1) printf("%d\n", m/2);
			else if (m%4==0) printf("%d\n", m/2-1);
			else printf("%d\n", m/2-2);
		}
		else
		{
			int m=(num[n-2]-'0')*10+num[n-1]-'0';
			ans[0]=1;
			for (int i=0; i<n; i++)
				ans[i+1]=num[i]-'0';
			int x=0;
			for (int i=ans[0]; i<=n; i++)
			{
				int tmp=(x*10+ans[i])/2;
				x=(x*10+ans[i])%2;
				ans[i]=tmp;
			}
			while (!ans[ans[0]]) ans[0]++;
			if (m&1) ;
			else if (m%4==0) dec(1);
			else dec(2);
			for (int i=ans[0]; i<=n; i++)
				printf("%d", ans[i]);
			puts("");
		}
		if (test) puts("");
	}
	return 0;
}
