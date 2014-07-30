#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MOD = 1e9 + 7;
const int MAXN = 100000 + 10;

int a[MAXN], n;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		int mx = 0;
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
			if (a[i] > mx) mx = a[i];
		}
		int ret = 1;
		for (int i = 0; i < n; ++ i) {
			if (a[i] == mx) {
				ret <<= 1;
				if (ret >= MOD) ret -= MOD;
			}
		}
		ret = (ret - 1) % MOD;
		if (ret < 0) ret += MOD;
		printf("%d\n", ret);
	}
	return 0;
}
