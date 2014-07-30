#include <cstdio>

int dp[3000000];

int main() {
	int N = 2000000;
	for (int i = 1; i <= N; ++ i) {
		for (int j = i; j <= N; j += i) {
			int c = j / i + 1 - i;
			if (c >= 4 && (c & 1) == 0) dp[j] ++;
		}
	}
	while (scanf("%d", &N) == 1 && N) {
		printf("%d\n", dp[N * 2]);
	}
	return 0;
}
