#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
typedef long long LL;
const int MOD = 1e9 + 7;

int pow_mod(int a, int n) {
	int ret = 1;
	for (; n; n >>= 1, a = (LL)a * a % MOD) {
		if (n & 1) ret = (LL)ret * a % MOD;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1, n; cas <= T; ++ cas) {
		scanf("%d", &n);
		printf("Case #%d: %lld\n", cas, (LL)n * pow_mod(2, n - 1) % MOD);
	}
	return 0;
}
