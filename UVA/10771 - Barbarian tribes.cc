#include <cstdio>

int main() {
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3 && k) {
		if (m & 1) puts("Keka");
		else puts("Gared");
	}
	return 0;
}
