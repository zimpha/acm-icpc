#include <stdio.h>

int main() {
	int N, C;
	char *o = &N, *n = &C;
	while (scanf("%d", &N) == 1) {
		*n = *(o + 3);
		*(n + 1) = *(o + 2);
		*(n + 2) = *(o + 1);
		*(n + 3) = *o;
		printf("%d converts to %d\n", N, C);
	}
	return 0;
}
