#include <cmath>
#include <cstdio>

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		double A, B; scanf("%lf%lf", &A, &B);
		printf("%.10f %.10f\n", sqrt(B * B - A * A), sqrt(A * A + B * B));
	}
	return 0;
}
