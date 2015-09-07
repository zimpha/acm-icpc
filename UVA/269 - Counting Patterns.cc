#include <cstdio>
#include <cstdlib>
#include <cstring>

int a[16], b[32], sum, n, k;
int tup[131072][16], cnt;

inline int cmp(int b[]) {
	int i;
	for (i = 0; a[i] == b[i]; ++ i);
	return (b[i] > a[i] && i < n) ? 1 : 0;
}

inline void check() {
	int i, j;
	for (i = 0, j = 0; i < n; ++ i) b[j ++] = a[i];
	for (i = 0; i < n; ++ i) b[j ++] = a[i];
	for (i = 1; i < n; ++ i) if (b[i] == a[0] && cmp(b + i)) return;
	for (i = 1; i < (n << 1); ++ i) b[i] = -b[i];
	for (i = 1; i < n; ++ i) if (b[i] == a[0] && cmp(b + i)) return;

	for (i = n, j = 0; i --;) b[j ++] = a[i];
	for (i = n; i --; ) b[j ++] = a[i];
	for (i = 0; i < n; ++ i) if (b[i] == a[0] && cmp(b + i)) return;
	for (i = 0; i < (n << 1); ++ i) b[i] = -b[i];
	for (i = 0; i < n; ++ i) if (b[i] == a[0] && cmp(b + i)) return;
	for (int i = 0; i < n; ++ i) tup[cnt][i] = a[i]; cnt ++;
}

void dfs(int dep) {
	if (dep == (n - 1)) {
		if (-a[0] <= sum && sum <= a[0]) {
			a[dep] = -sum;
			check();
		}
		return;
	}
	if (abs(sum) > (n - dep) * a[0]) return;
	for (a[dep] = -a[0]; a[dep] < a[0]; ++ a[dep]) {
		if (a[dep - 1] == a[0] && a[dep] > a[1]) return;
		sum += a[dep]; dfs(dep + 1); sum -= a[dep];
	}
	if (a[dep] == a[0] && a[dep - 1] <= a[1]) {
		sum += a[0]; dfs(dep + 1); sum -= a[0];
	}
}

int main() {
	int cas = 0;
	while (scanf("%d%d", &n, &k) == 2) {
		if (cas ++) puts("");
		if (n == 1) {
			puts("1\n(0)");
			continue;
		}
		a[n] = -0x1fffffff;
		cnt = 0;
		for (a[0] = 0; a[0] <= k; ++ a[0]) {
			sum = a[0];
			dfs(1);
		}
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; ++ i) {
			for (int j = 0; j < n; ++ j)
				printf(j ? ",%d" : "(%d", tup[i][j]);
			puts(")");
		}
	}
	return 0;
}
