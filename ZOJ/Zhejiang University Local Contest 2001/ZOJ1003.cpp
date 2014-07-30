#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int flaga, flagb;

void dfs(int a, int b, int n)
{
	if (b==1)
	{
		flagb=1;
		if (a==1) flaga=1;
	}
	if (n>100||flaga&&flagb) return;
	if (a%n==0) dfs(a/n, b, n+1);
	if (b%n==0) dfs(a, b/n, n+1);
	dfs(a, b, n+1);
	return;
}

int main()
{
	int a, b;
	while (scanf("%d%d", &a, &b)!=EOF)
	{
		if (a<b) swap(a, b);
		flaga=flagb=0;
		dfs(a, b, 2);
		if (flaga) printf("%d\n",a);
		else if (flagb) printf("%d\n",b);
		else printf("%d\n",a);
	}
	return 0;
}
