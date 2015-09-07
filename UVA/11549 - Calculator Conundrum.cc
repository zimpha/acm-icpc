#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

int get_next(int n, int k) {
	if (!k) return 0;
	LL kk = (LL)k * k;
	static int buf[100];
	int ret = 0, L = 0;
	for (; kk > 0; kk /= 10) buf[L ++] = kk % 10;
	if (n > L) n = L;
	for (int i = 0; i < n; ++ i) ret = ret * 10 + buf[-- L];
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, k; scanf("%d%d", &n, &k);
		int ans = k, k1 = k, k2 = k;
		do {
			k1 = get_next(n, k1);
			k2 = get_next(n, k2); ans = max(ans, k2);
			k2 = get_next(n, k2); ans = max(ans, k2);
		} while (k1 != k2);
		printf("%d\n", ans);
	}
	return 0;
}
