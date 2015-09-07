#include <cstdio>
#include <cstring>

typedef long long LL;

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		LL N, a = 1, b, x;
		scanf("%lld%lld", &N, &b);
		for (int i = 1; i < N; ++ i) {
			scanf("%lld", &x);
			a = a * x + b; b = b * x;
			x = gcd(a, b);
			a /= x; b /= x;
		}
		b = b * N;
		x = gcd(a, b);
		a /= x; b /= x;
		printf("Case %d: %lld/%lld\n", cas, b, a);
	}
	return 0;
}
