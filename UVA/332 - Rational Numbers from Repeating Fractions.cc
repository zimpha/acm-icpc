#include <cstdio>
#include <cstring>

typedef long long LL;

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	LL p[15]; p[0] = 1;
	for (int i = 1; i < 15; ++ i) p[i] = p[i - 1] * 10;
	int k, j, cas = 0;
	while (scanf("%d", &j) == 1 && j != -1) {
		LL X, a, b;
		char st[20];
		scanf(" 0.%s", st);
		k = strlen(st) - j;
		sscanf(st, "%lld", &X);
		if (j) {
			a = X - X / p[j];
			b = p[k + j] - p[k];
		} else {
			a = X; b = p[k];
		}
		X = gcd(a, b);
		a /= X; b /= X;
		printf("Case %d: %lld/%lld\n", ++ cas, a, b);
	}
	return 0;
}
