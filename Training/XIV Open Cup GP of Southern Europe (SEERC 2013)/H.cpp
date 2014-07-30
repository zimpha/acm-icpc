#include <cstdio>

int main() {
	freopen("h.in", "r", stdin);
	int n; scanf("%d", &n);
	n = (n % 3) ? 1 : 0;
	printf("%d\n", n);
	fclose(stdin); return 0;
}
