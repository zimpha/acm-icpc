#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;;
const int MAXN = 2000 + 10;

char a[MAXN][MAXN];
int dp[MAXN][MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) {
		scanf("%s", a[i] + 1);
	}
	memset(dp, 0, sizeof(dp));
	for (int i = n - 1; i >= 0; -- i) {
		for (int j = 1; j <= m; ++ j) {
			if (a[i][j] != '1') continue;
			dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
		}
	}
	long long ret = 0;
	for (int i = 0; i < n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			ret += (long long)dp[i][j];
		}
	}
	printf("%lld\n", ret);
	return 0;
}
