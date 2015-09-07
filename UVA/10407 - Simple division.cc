#include <cstdio>
#include <cstring>
#include <cstdlib>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int num[1005], n = 0;
	while (scanf("%d", &num[n]) == 1 && num[n] != 0) {
		do {
			n ++; scanf("%d", &num[n]);
		}while (num[n] != 0);
		int ret = num[1] - num[0];
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < i; ++ j) {
				ret = gcd(ret, abs(num[i] - num[j]));
			}
		} n = 0;
		printf("%d\n", ret); n = 0;
	}
	return 0;
}
