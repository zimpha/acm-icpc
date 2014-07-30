#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	int T, N, x; scanf("%d", &T);
	while (T --) {
		long long ret = 0, c2 = 0, c1 = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &x);
			if (x <= 1) continue;
			if (x == 2) ret += c2, c1 ++;
			else ret += c1, c1 ++, c2 ++;
		}
		printf("%lld\n", ret);
	}
	return 0;
}
