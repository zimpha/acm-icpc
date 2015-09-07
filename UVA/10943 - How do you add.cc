#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MOD = 1000000;
const int MAXN = 100 + 10;

int F[MAXN][MAXN];

int solve(int n, int k) {
	if (k == 0) return 0;
	if (F[n][k] != -1) return F[n][k];
	if (k == 1) return F[n][k] = 1;
	F[n][k] = 0;
	for (int i = 0; i <= n; ++ i) {
		F[n][k] = (F[n][k] + solve(n - i, k - 1)) % MOD;
	}
	return F[n][k];
}

int main() {
	int N, K;
	memset(F, -1, sizeof(F));
	while (scanf("%d%d", &N, &K) == 2 && N) {
		solve(N, K);
		printf("%d\n", F[N][K]);
	}
	return 0;
}
