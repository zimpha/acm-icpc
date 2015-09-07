#include <cstdio>
#include <cstring>

const int MAXN = 1000010;

double dp[MAXN];
int vis[MAXN];
int N, d, s, a, f;

double solve(int n) {
	if (vis[n] == f) return dp[n];
	vis[n] = f;
	if (n == 1) return dp[n] = 0;
	if (n & 1) return dp[n] = (solve(n + 1) + solve(n - 1) + a + s) / 2.0;
	else return dp[n] = solve(n / 2) + d;
}

int main() {
	int T; scanf("%d", &T);
	for (f = 1; f <= T; ++ f) {
		scanf("%d%d%d%d", &N, &d, &s, &a);
		printf("%.3f\n", solve(N) + a + d + s);
	}
	return 0;
}
