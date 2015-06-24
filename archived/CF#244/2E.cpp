#include <cstdio>

const int MAXN = 1000000 + 10;

int a[MAXN], n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
	long long ret = 0;
	for (int i = 1, j = n; i <= j; i += m, j -= m)
		ret += a[j] - a[i];
	printf("%I64d\n", ret << 1);
	return 0;
}
