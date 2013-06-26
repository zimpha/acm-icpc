#include <cstdio>
#include <cstring>

const int MAXN=200;

int ans[MAXN];
int n;

int get(int n)
{
	int m=2;
	while (1)
	{
		bool flag=true;
		int out=0;
		for (int i=2; i<n; i++)
			out=(out+m)%i;
		if (out==0) break;
		m++;
	}
	return m;
}

int main()
{
	memset(ans,0,sizeof(ans));
	while (scanf("%d", &n)==1&&n)
	{
		if (!ans[n]) ans[n]=get(n);
		printf("%d\n", ans[n]);
	}
	return 0;	
}
