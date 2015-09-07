#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n,k,g;
int a[30000],zone[30000],f[30000];
int idx[30000];
int T;
int X,Y;

void add(int x)
{
	for(int i = x;i <= n;i += (i & -i)) f[i]++;
}

int sum(int x)
{
	int ret = 0;
	for(int i = x;i > 0;i -= (i & -i)) ret += f[i];
	return ret;
}

int main()
{
	scanf("%d",&T);
	int cas = 0;
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i++) scanf("%d",a+i);
		g = (n+k-1)/k;
		for(int i = 0;i < g;i++) zone[i] = i*k+1;
		
		for(int i = 1;i <= n;i++)
		{
			int p = (a[i] - 1)/k;
			a[i] = zone[p]++;
		}
		
		X = 0;
		for(int i = 1;i <= n;i++) X = max(X,abs(a[i] - i));
		
		Y = 0;
		for(int i = 1;i <= n;i++) f[i] = 0;
		for(int i = n;i > 0;i--)
		{
			int now = i + sum(a[i]);
			Y += now - a[i];
			add(a[i]);
		}
		cas++;
		printf("Case %d: %d\n",cas,Y - X);
	}
	return 0;
}
