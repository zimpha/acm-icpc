#include <cmath>
#include <cstdio>
#include <cstring>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int a[100], n;
	while (scanf("%d", &n) == 1 && n) {
		int ret = 0;
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a[i]);
			for (int j = 0; j < i; ++ j) 
				ret += (gcd(a[i], a[j]) == 1);
		}
		n = n * (n - 1) / 2;
		if (ret == 0) puts("No estimate for this data set.");
		else printf("%.6f\n", sqrt(6.0 * n / (double)ret));
	}
	return 0;
}
