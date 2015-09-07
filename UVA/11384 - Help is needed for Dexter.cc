#include <cstdio>
#include <cstring>

int f(int n) {
	return (n == 1) ? 1 : f(n / 2) + 1;
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", 32 - __builtin_clz(n));
	}
	return 0;
}
