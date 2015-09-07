#include <cstdio>
#include <cstring>
#include <cmath>


int main() {
	int cas = 0, a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		if (cas) printf("\n"); cas ++;
		double ab = a * 1.0 / b, p = 1.0;
		for (int i = 1; i <= b; ++ i) {
			int t = (int)(a * 1.0 / b * i + 0.5);
			if (fabs(t * 1.0 / i - ab) < p) {
				printf("%d/%d\n", t, i);
				p = fabs(t * 1.0 / i - ab);
			}
			if (t * b == i * a) break;
		}
	}
	return 0;
}

