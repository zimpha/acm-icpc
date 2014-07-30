#include <cstdio>
#include <cstring>

typedef long long LL;

const int MAXN = 1000005;
const int MOD = 1000000007;

int f[MAXN], g[3][MAXN];
int N, M, K;

inline void fix(int &x) {
	while (x < 0) x += MOD;
	while (x >= MOD) x -= MOD;
}

int main() {
	while (scanf("%d%d%d", &N, &M, &K) == 3) {
		f[0] = 1;
		for (int i = 1; i <= N; ++ i) {
			f[i] = 3ll * f[i-1] % MOD;
			if (i - 1 == K) f[i] = f[i] - 1;
			else if (i - 1 > K) f[i] = f[i] - 2ll * f[i - K - 2];
			fix(f[i]);
		}
		g[0][1] = g[1][1] = g[2][1] = 1;
		if (M == 1) g[0][1] = 0;
		for (int i = 2; i <= N; ++ i) {
			LL tmp = ((LL)g[0][i - 1] + g[1][i - 1] + g[2][i - 1]) % MOD;
			g[0][i] = g[1][i] = g[2][i] = tmp;
			if (i == M) g[0][i] = g[0][i] - 1;
			else if (i > M) g[0][i] = g[0][i] - g[1][i - M] - g[2][i - M];

			if (i - 1 == K) g[1][i] = g[1][i] - 1;
			else if (i - 1 > K) g[1][i] = g[1][i] - g[0][i - K - 1] - g[2][i - K - 1];
			fix(g[0][i]); fix(g[1][i]); fix(g[2][i]);
		}
		LL ans = ((LL)f[N] - g[0][N] - g[1][N] - g[2][N]) % MOD;
		printf("%lld\n", (ans + MOD) % MOD);
	}
	return 0;
}
