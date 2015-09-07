#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long LL;

int main() {
	int n, m;
	while (scanf("%d", &n) == 1 && n) {
		printf("%d ", n);
		m = (int)sqrt(n + 0.5);
		int t[20], k = 0;
		for (int i = 2; i <= m; ++ i) {
			if (n % i == 0) {
				t[k] = 0;
				while (n % i == 0) {
					t[k] ++; n /= i;
				}
				k ++;
			}
		}
		if (n > 1) t[k ++] = 1;
		LL ret = 0;
		for (int mask = 0; mask < (1 << k); mask ++) {
			LL a = 1, b = 1;
			for (int i = 0; i < k; ++ i) {
				if ((mask >> i) & 1) {
					b *= (LL)(t[i] + 1);
				} else {
					a *= (LL)t[i];
				}
			}
			ret += a * b;
		}
		printf("%lld\n", (ret + 1) / 2LL);
	}
	return 0;
}
