#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 105;
const int MAXK = 105;
const int MOD = 1000000009;
typedef long long LL;

char s1[MAXN], s2[MAXN];
int comb[MAXN][MAXN];
int dp[MAXK][MAXN];
int N, K, M;

void calc_comb(int N) {
	memset(comb, 0, sizeof(comb));
	comb[0][0] = 1;
	for (int i = 1; i <= N; ++ i) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}
}

int main() {
	while (scanf("%d %d %d", &N, &K, &M) == 3) {
		calc_comb(N);
		scanf("%s%s", s1, s2);
		int ret = 0;
		for (int i = 0; i < N; ++ i)
			ret += (s1[i] != s2[i]);
		memset(dp, 0, sizeof(dp));
		dp[0][ret] = 1;
		for (int i = 1; i <= K; ++ i)
			for (int j = 0; j <= N; ++ j)
				for (int k = 0; k <= M && k <= j; ++ k) {
					if (N - j < M - k) continue;
					dp[i][j + M - 2 * k] = (dp[i][j + M - 2 * k] + (LL)dp[i - 1][j] * comb[j][k] % MOD * comb[N - j][M - k] % MOD) % MOD;
				}
		printf("%d\n", dp[K][0]);
	}
	return 0;
}
