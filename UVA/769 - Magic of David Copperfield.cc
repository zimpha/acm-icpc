#include <stdio.h>
#include <string.h>

int t, n, k, m;

void init() {
	scanf("%d", &n);
	k = 2 * n + 1;
	m = 2;
}

void solve() {
	while (k && m < 2 * n) {
		printf("%d", k);
		for (int i = 1; i < m; i++) {
			if (i > n || m - i > n) continue;
			printf(" %d", (i - 1) * n + (m - i));
		}
		printf("\n");
		m++; k += 2;
	}
	if (t) printf("\n");
}

int main() {
	scanf("%d", &t);
	while (t--) {
		init();
		solve();
	}
	return 0;
}
