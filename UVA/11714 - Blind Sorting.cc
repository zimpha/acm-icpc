#include <cmath>
#include <cstdio>
#include <cstdlib>

int main() {
	int n; 
	while (scanf("%d", &n) == 1) {
		printf("%d\n", n + (int)ceil(log2(n)) - 2);
	}
	return 0;
}
