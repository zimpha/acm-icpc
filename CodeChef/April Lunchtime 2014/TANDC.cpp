#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MOD = 1e9 + 7;

LL power_mod(LL a, LL n, LL p) {
	LL ret = 1;
	for (a %= p; n; a = a * a % p, n >>= 1) {
		if (n & 1) ret = ret * a % p;
	}
	return ret;
}

bool check(LL n) {
	for (int i = 2; i * i <= n; ++ i)
		if (n % i == 0) return false;
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		LL M, R;
		scanf("%lld%lld", &M, &R);
		 LL ret = power_mod(M, R, MOD);
		ret = (ret - 1 + MOD) % MOD;
		ret = ret * power_mod(M - 1, MOD - 2, MOD) % MOD;
		ret = (ret - R + MOD) % MOD;
		printf("%lld\n", ret);
	}
}
