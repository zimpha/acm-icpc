#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[5][32], r[5];
int N, K;

void solve() {
	for (int i = 1; i < K; ++ i) {
		for (int m1 = 0; m1 < 32; ++ m1)
			for (int m2 = 0; m2 < 32; ++ m2) {
				if (m1 & m2) continue;
				dp[i][m1 | m2] = max(dp[i][m1 | m2], dp[i - 1][m1] + dp[0][m2]);
			}
	}
	printf("%d\n", dp[K - 1][31]);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &K); K = min(K, 5);
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d%d%d%d", &r[0], &r[1], &r[2], &r[3], &r[4]);
			for (int mask = 0; mask < 32; ++ mask) {
				int ret = 0;
				for (int j = 0; j < 5; ++ j) 
					if (mask & (1 << j)) ret += r[j];
				dp[0][mask] = max(dp[0][mask], ret);
			}
		}
		solve();
	}
	return 0;
}
