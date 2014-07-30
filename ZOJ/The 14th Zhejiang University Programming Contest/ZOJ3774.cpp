#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long LL;

LL pow_mod(LL a, LL n, LL p) {
	LL ret = 1;
	for (a %= p; n; n >>= 1, a = a * a % p) {
		if (n & 1) ret = ret * a % p;
	}
	return ret;
}

LL modsqr(LL a, LL p) {
	LL q = p - 1, s = 0, z;
	if (p == 2) return (a & 1) ? 1 : -1;
	if (pow_mod(a, (p - 1) >> 1, p) != 1) return -1;
	while (q % 2 == 0) s ++, q >>= 1;
	if (s == 1)return pow_mod(a, (p + 1) >> 2, p);
	while (1) {
		z = 1 + rand() % (p - 1);
		if (pow_mod(z, (p - 1) >> 1, p) != 1) break;
	}
	LL c = pow_mod(z, q , p), r = pow_mod(a, (q + 1) >> 1, p);
	LL t = pow_mod(a, q, p), m = s, b, i;
	while (1) {
		if (t % p == 1) break;
		for (i = 1; i < m && pow_mod(t, 1 << i, p) != 1; i ++);
		b = pow_mod(c, 1 << (m - i - 1), p);
		r = (r * b) % p; c = (b * b) % p; t = (t * c) % p;
		m = i;
	}
	if (r > p - r) r = p - r;
	return r;
}

LL inv(LL a, LL p) {
	return pow_mod(a, p - 2, p);
}
//q + q^2 + .. + q ^ n
LL calc(LL q, LL n, LL p) {
	if (n == 0 || q == 0) return 0;
	if (q == 1) return n % p;
	else return q * inv(q - 1, p) % p * (pow_mod(q, n, p) - 1 + p) % p; 
}

int main() {
	LL p = 1e9 + 9, s = 383008016;
	LL u = (p + s + 1) >> 1, v = 1 - u + p;
	int T; scanf("%d", &T);
	while (T --) {
		LL n, k; scanf("%lld%lld", &n, &k);
		LL ret = 0;
		LL uk = pow_mod(u, k, p), vu = v * inv(u, p) % p;
		LL q = uk, comb = 1;
		for (int i = 0; i <= k; ++ i) {
			ret = (ret + comb * calc(q, n, p)) % p;
			comb = comb * (k - i) % p * inv(i + 1, p) % p;
			comb = comb * (p - 1) % p;
			q = q * vu % p;
		}
		ret = ret * inv(pow_mod(s, k, p), p) % p;
		printf("%lld\n", ret);
	}
	return 0;
}
