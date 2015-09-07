#include <cstdio>

const int MAXN = 1000000 + 10;

double dp[MAXN];

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, K; scanf("%d%d", &N, &K);
		dp[0] = 0;
		for (int i = 1; i <= K + 1; ++ i) dp[i] = dp[i - 1] + 1;
		for (int i = K + 2; i <= N; ++ i) {
			dp[i] = dp[i - 1];
			dp[i] += 2.0 * dp[i - K - 1] / i + 1;
		}
		printf("Case #%d: %.4f\n", cas, dp[N] - dp[N - 1]);
	}
	return 0;
}
