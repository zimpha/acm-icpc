#include <cstdio>

int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		if (n <= 3) puts("1");
		else if (n == 4) puts("2");
		else printf("%d\n", n);
	}
	return 0;
}
