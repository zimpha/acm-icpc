#include <cstdio>
#include <cstring>

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		long long N; scanf("%lld", &N);
		printf("%lld\n", N / 2ll);
	}
	return 0;
}
