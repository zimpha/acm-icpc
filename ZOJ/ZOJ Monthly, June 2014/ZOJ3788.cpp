#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int SIZE = 1000;
const int MOD = 5767169;

typedef long long LL;

int fac[MOD], inv[MOD], rv[MOD];
int N, A, B, a, b;

LL power_mod(LL a, LL b, LL mod) {
	LL ret = 1;
	for (a %= MOD; b; b >>= 1, a = a * a % MOD) {
		if (b & 1) ret = ret * a % MOD;
	}
	return ret;
}

void init() {
	fac[0] = inv[0] = fac[1] = inv[1] = rv[1] = 1;
	for (int i=2; i<MOD; i++) {
		rv[i] = (LL)rv[MOD % i] * (MOD - MOD / i) % MOD;
		fac[i]=((LL)fac[i-1]*i)%MOD;
		inv[i] = (LL)inv[i - 1] * rv[i] % MOD;
	}
}

LL lucas(LL n, LL m, LL mod, int inv[], int fac[]) {
	if (n == 0 && m == 0) return 1;
	LL a = n % mod, b = m % mod;
	if (b > a) return 0;
	return (((((lucas(n / mod, m / mod, mod, inv, fac) * fac[a]) % mod) * inv[b]) % mod) * inv[a - b]) % mod;
}

LL binomal(int p, int q) {
	return lucas(p + q, q, MOD, inv, fac);
}

vector<int> rec(int k) {
	if (k < b) {
		vector<int> s(b, 0); s[k] = 1;
		return s;
	}
	vector<int> h(rec(k >> 1));
	vector<int> s(b << 1 | k & 1, 0);
	int *u = &s[k & 1];
	for(int i = 0; i < b; ++ i)
		for(int j = 0; j < b; ++ j)
			u[i + j] = (u[i + j] + h[i] * (LL)h[j]) % MOD;
	for(int k = s.size() - 1; k >= b; -- k) {
		s[k - b] = (s[k - b] + s[k] * (LL)B) % MOD;
		s[k - a] = (s[k - a] + s[k] * (LL)A) % MOD;
	}
	s.resize(b);
	return s;
}

int main() {
	init();
	while (scanf("%d%d%d%d%d", &A, &B, &a, &b, &N) == 5) {
		if (a == b) {
			int t = N % a;
			if (t == 0) printf("%lld\n", power_mod(A + B, N / a, MOD));
			else printf("0\n");
			continue;
		}
		if (a > b) swap(a, b), swap(A, B);
		if (b <= SIZE) {
			LL ret = rec(N + b - 1).back();
			printf("%lld\n", ret);
		}
		else {
			LL ret=0;
			for (int p, q = N / b; q >= 0; -- q)
				if ((N - b * q) % a == 0) {
					p = (N - b * q) / a;
					ret=(ret + power_mod(A, p, MOD) * power_mod(B, q, MOD) % MOD * binomal(p, q) % MOD) % MOD;
				}
			printf("%lld\n", ret);
		}
	}
	return 0;
}
