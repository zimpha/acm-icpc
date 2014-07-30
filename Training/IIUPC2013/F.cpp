#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int x, y, r;
		scanf("%d%d%d", &x, &y, &r);
		double d = sqrt(x * x + y * y);
		printf("%.2f %.2f\n", (double)r - d, (double)r + d);
	}
	return 0;
}
