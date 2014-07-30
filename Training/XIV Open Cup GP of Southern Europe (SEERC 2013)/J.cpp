#include <cstdio>

int main() {
	freopen("j.in", "r", stdin);
	int n1, n2; scanf("%d%d", &n1, &n2);
	int n = n2 - n1 + 1;
	printf("%d\n", n * (n - 1) / 2);
	fclose(stdin);
	return 0;
}
