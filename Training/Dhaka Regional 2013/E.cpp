#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000003;

LL fac[MOD + 10], inv[MOD + 10];
LL PX[MOD + 10], PY[MOD + 10], PZ[MOD + 10];

LL pow_mod(LL a, LL n) {
	LL ret = 1;
	for (a %= MOD; n; a = a * a % MOD, n >>= 1) {
		if (n & 1) ret = ret * a % MOD;
	}
	return ret;
}

LL comb(int N, int M) {
	return fac[N] * inv[M] % MOD * inv[N - M] % MOD;
}

int main() {
	int T; scanf("%d", &T);
	PX[0] = PY[0] = PZ[0] = fac[0] = inv[0] = 1;
	for (int i = 1; i <= MOD; ++ i) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = pow_mod(fac[i], MOD - 2);
	}
	for (int cas = 1; cas <= T; ++ cas) {
		LL A, B, X, Y, Z;
		scanf("%lld%lld%lld%lld%lld", &A, &B, &X, &Y, &Z);
		X %= MOD, Y %= MOD, Z %= MOD;
		for (int i = 1; i < MOD; ++ i) {
			PX[i] = PX[i - 1] * X % MOD;
			PY[i] = PY[i - 1] * Y % MOD;
			PZ[i] = PZ[i - 1] * Z % MOD;
		}
		LL ret = 1;
		while (A || B) {
			LL a = A % MOD, b = B % MOD, tmp = 0;
			for (int i = 0; i <= a && i <= b; ++ i) {
				tmp += comb(a + b - i, a - i) * comb(b, i) % MOD * PX[a - i] % MOD * PY[b - i] % MOD * PZ[i] % MOD;
				tmp %= MOD;
			}
			ret = ret * tmp % MOD;
			A /= MOD, B /= MOD;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
