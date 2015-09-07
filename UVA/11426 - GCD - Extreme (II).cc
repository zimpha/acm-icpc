#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long LL;

const int MAXN = 4000001;

LL phi[MAXN], g[MAXN];

void phi_table(int n) {
	for (int i = 1; i < n; ++ i) phi[i] = 0;
	for (int i = 2; i < n; ++ i) {
		if (!phi[i]) {
			for (int j = i; j < n; j += i) {
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main() {
	phi_table(MAXN);
	memset(g, 0, sizeof(g));
	for (int i = 1; i < MAXN; ++ i) {
		for (int j = i * 2; j < MAXN; j += i) {
			g[j] += (LL)i * phi[j / i];
		}
	}
	for (int i = 3; i < MAXN; ++ i) g[i] += g[i - 1];
	int n;
	while (scanf("%d", &n) == 1 && n) {
		printf("%lld\n", g[n]);
	}
	return 0;
}
