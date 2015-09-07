#include <cstdio>

int main() {
	int T, n; scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		if (n & 1) printf("%d\n", (n >> 1) * (n >> 1));
		else printf("%d\n", (n >> 1) * (n / 2 - 1));
	}
	return 0;
}
