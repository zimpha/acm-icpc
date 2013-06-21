#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXD=100005;
const int MAXP=355;
const int inf=1000000000;

int dp[MAXD], l[MAXP], c[MAXP];
int d, p;

int main()
{
	freopen("plumb.in", "r", stdin);
	freopen("plumb.out", "w", stdout);
	scanf("%d%d", &d, &p);
	for (int i=0; i<p; i++)
		scanf("%d%d", l+i, c+i);
	memset(dp, 0, sizeof(dp));
	dp[0]=inf;
	for (int i=0; i<p; i++)
		for (int j=d; j>=l[i]; j--)
			dp[j]=max(dp[j], min(dp[j-l[i]], c[i]));
	printf("%d\n", dp[d]);
	fclose(stdin); fclose(stdout);
}
