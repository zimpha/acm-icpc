#include <cstdio>

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		double N, M, A, B;
		scanf("%lf%lf%lf%lf", &N, &M, &A, &B);
		double ret = (A * M + B * M - A * N) / B;
		if (ret > -1e-8 && ret < 10 + 1e-8) printf("Case #%d: %.2f\n", cas, ret);
		else printf("Case #%d: Impossible\n", cas);
	}
	return 0;
}
