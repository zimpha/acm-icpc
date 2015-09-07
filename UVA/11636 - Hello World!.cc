#include <stdio.h>
#include <math.h>

double n;

int main() {
	int cas = 0;
	while (~scanf("%lf", &n) && n > 0) {
		printf("Case %d: %d\n", ++ cas, n == 1 ? 0 : (int)log2(n - 1) + 1);
	}
	return 0;
}  
