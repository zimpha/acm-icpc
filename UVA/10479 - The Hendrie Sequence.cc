#include <cstdio>
#include <cstring>

typedef unsigned long long ULL;

ULL solve(ULL n) {
	ULL m = 0;
	while ((1ULL << m) < n) ++ m;
	if ((1ULL << m) == n) return m;
	n = (1ULL << m) - n - 1;
	if (n < m - 1) return 0;
	else n -= m - 1;
	if (n < m - 2) return 1;
	else n-= m - 2;
	for (ULL k = 1; ; ++ k) {
		ULL l = 1ULL << k;
		for (ULL i = 0; i < m - k - 2; ++ i) {
			if (n < l) return solve(2 * l - n);
			else n -= l;
		}
	}
	return 0;
}

int main() {
	ULL n;
	while (scanf("%llu", &n) == 1 && n) {
		printf("%llu\n", solve(n));
	}
	return 0;
}
