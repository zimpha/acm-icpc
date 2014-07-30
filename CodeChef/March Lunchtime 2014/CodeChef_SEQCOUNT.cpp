#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 10;
const int MOD = 1e9 + 7;

int dp[2][MAXN], sum[MAXN];

int main() {
	int N, K, D; 
	scanf("%d%d%d", &N, &K, &D);
	for (int i = 1, s = 0; i <= K; ++ i) {
		s += i;
		if (s > N) {
			puts("0");
			return 0;
		}
	}
	memset(dp, 0, sizeof(dp)); dp[0][0] = 1;
	for (int i = 1; i <= K; ++ i) {
		for (int j = 0; j < K - i + 1; ++ j) sum[j] = 0;
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		for (int j = 0; j <= N; ++ j) {
			dp[i & 1][j] = sum[j % (K - i + 1)];
			sum[j % (K - i + 1)] += dp[(i & 1) ^ 1][j];
			if (sum[j % (K - i + 1)] >= MOD) sum[j % (K - i + 1)] -= MOD;
			if (j - (K - i + 1) * D >= 0) {
				sum[j % (K - i + 1)] += MOD - dp[(i & 1) ^ 1][j - (K - i + 1) * D];
				if (sum[j % (K - i + 1)] >= MOD) sum[j % (K - i + 1)] -= MOD;
			}
		}
	}
	printf("%d\n", dp[K & 1][N]);
	return 0;
}
