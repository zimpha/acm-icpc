#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=50;

int num[MAXN];
int n;

int main()
{
	freopen("cowdom.in", "r", stdin);
	freopen("cowdom.out", "w", stdout);
	memset(num, 0, sizeof(num));
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		num[i]=a+b;
	}
	sort(num, num+n);
	for (int i=1; i<n; i++)
	{
		num[i]+=num[i-1]/10;
		num[i-1]%=10;
	}
	while (num[n]) n++;
	for (int i=n-1; i>=0; i--)
		printf("%d", num[i]);
	puts("");
	fclose(stdin); fclose(stdout);
	return 0;
}
