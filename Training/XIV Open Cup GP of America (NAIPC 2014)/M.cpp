#include <cstdio>

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		double X; char Y;
		scanf("%lf %c", &X, &Y);
		if (X >= 2.5 && Y <= 'C') puts("Eligible");
		else puts("Ineligible");
	}
	return 0;
}
