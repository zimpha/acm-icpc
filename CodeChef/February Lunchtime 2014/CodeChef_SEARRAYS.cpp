#include <cstdio>
#include <cstring>
const int MOD = 1e9 + 7;
const int MAXN = 100000 + 10;

int dp[MAXN], n, k;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++ i) dp[i] = 0;
		dp[n] = 1;
		for (int i = n - 1; i >= 0; -- i) {
			dp[i] = dp[i + 1];
			if (i + k <= n) dp[i] += dp[i + k];
			if (dp[i] >= MOD) dp[i] -= MOD;
		}
		printf("%d\n", dp[0]);
	}
	return 0;
}
