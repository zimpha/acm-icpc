#include <cstdio>
#include <cstring>
#include <cstdlib>

int pow_mod(int a, int b, int p) {
	int ret = 1;
	for (a %= p; b; b >>= 1, a = a * a % p) {
		if (b & 1) ret = ret * a % p;
	}
	return ret;
}

int pp[50];

int main() {
	int ret = 0;
	int sum = 0;
	for (int i = 1; i <= 42; ++ i) pp[i] = pow_mod(i, i, 7), sum = (sum + pp[i]) % 7;
	int T; scanf("%d", &T);
	while (T --) {
		int N; scanf("%d", &N);
		int t = N / 42;
		int r = N % 42;
		int ret = 0;
		for (int i = 1; i <= r; ++ i) ret = (ret + pp[i]) % 7;
		ret = (ret + t * sum) % 7;
		if (ret == 0) puts("Saturday");
		else if (ret == 1) puts("Sunday");
		else if (ret == 2) puts("Monday");
		else if (ret == 3) puts("Tuesday");
		else if (ret == 4) puts("Wednesday");
		else if (ret == 5) puts("Thursday");
		else if (ret == 6) puts("Friday");
	}
	return 0;
}
