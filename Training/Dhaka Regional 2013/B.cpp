#include <cstdio>

int solve(long long a, long long b, long long c) {
	long long d = b > c ? b - c : c - b;
	int f = (a & 1) ? 2 : 1, s = 3 - f;
	if (!b && !c) return a ? 2 : 0;
	if (!b || !c) return (b > 2 || c > 2) ? s : 0;
	if (d == 0) return f;
	if (d <= 2) return (f == 1) ? 1 : 0;
	return 1;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N; scanf("%d", &N);
		long long L, B, a = 0, b = 0, c = 0;
		while (N --) {
			scanf("%lld%lld", &L, &B);
			if (B % 3 == 0) a += (L - 1) * (B - 1);
			else if (B % 3 == 1) b += (L - 1) * (B - 1);
			else b += (L - 1) / 2 * (B - 1), c += L / 2 * (B - 1);
		}
		int ret = solve(a, b, c);
		printf("Case %d: ", cas);
		if (ret == 0) puts("Draw");
		else if (ret == 1) puts("M");
		else puts("J");
	}
	return 0;
}
