#include <cstdio>
typedef long long LL;

LL a[100][100], ret[60];

int main() {
	for (int i = 0; i < 100; ++ i) {
		a[i][0] = a[i][i] = 1;
		for (int j = 1; j < i; ++ j)
			a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
	}
	int T; scanf("%d", &T);
	while (T --) {
		int R, C, m = 0;
		LL G;
		scanf("%d%d%lld", &R, &C, &G);
		while (G) {
			int i = C;
			while (a[i][C] <= G && i <= 99) ++ i;
			i --;
			ret[m ++] = a[i][C];
			G -= a[i][C];
			C --;
		}
		printf("%d\n", m);
		for (int i = 0; i < m; ++ i) {
			if (i) putchar(' ');
			printf("%lld", ret[i]);
		}
		puts("");
	}
	return 0;
}
