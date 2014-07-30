#include <cstdio>
#include <cstring>
#include <cstdlib>

int cnt[32], n;

int main() {
	scanf("%d", &n);
	long long ret = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++ i) {
		int x; scanf("%d", &x);
		for (int j = 0; j < 32; ++ j) {
			if ((x >> j) & 1) {
				ret += (long long)cnt[j] * (1LL << j);
				cnt[j]++;
			}
		}
	}
	printf("%lld\n", ret);
	return 0;
}
