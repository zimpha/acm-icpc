#include <cstdio>
#include <cstring>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("Case %d: %d\n", cas, (n + m) / gcd(n, m));
	}
	return 0;
}
