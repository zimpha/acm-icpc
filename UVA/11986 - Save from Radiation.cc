#include <stdio.h>

typedef long long LL;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		LL n, s = 1;
		scanf("%lld", &n); n ++;
		if (n == 1) printf("Case %d: 0\n", cas);
		else {
			int j;
			for (j = 0; s < n; j++) s *= 2;
			printf("Case %d: %d\n", cas, j);
		}
	}
	return 0;
}

