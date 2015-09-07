#include <cstdio>
#include <cstdlib>

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		if (n <= 3 || (n & 1)) puts("Impossible");
		else {
			printf("%d\n", 3 * n / 2);
			for (int i = 1; i < n; ++ i) printf("%d %d\n", i, i + 1);
			printf("%d %d\n", 1, n);
			for (int i = 1; i <= n / 2; ++ i) printf("%d %d\n", i, i + n / 2);
		}
	}
	return 0;
}
