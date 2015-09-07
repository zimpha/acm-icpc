#include <stdio.h>
#include <string.h>
 
int h, k, max, ans[10];
 
int len(int * num, int size) {
	if (!size) return 0;
	int dp[10][1000] = {1}, limit = num[size - 1] * h + 1;
	for (int t = 1; t <= h; ++ t) {
		for (int j = 0; j < num[0]; ++ j)
			dp[t][j] = dp[t - 1][j];
		for (int i = 0; i < size; ++ i) {
			for (int j = num[i]; j < limit; ++ j) {
				dp[t][j] += dp[t - 1][j] + dp[t - 1][j - num[i]];
			}
		}
	}
	int i;
	for (i = 1; i < limit && dp[h][i]; ++ i);
	return i - 1;
}
 
void find(int d, int * use, int used) {
	int l = len(use, used);
	if (used == k) {
		if (l > max) {
			max = l;
			memcpy(ans, use, sizeof(int) * k);
		}
		return;
	}
	for (d ++; d <= l + 1; d ++) {
		use[used] = d;
		find(d, use, used + 1);
	}
}
 
int main() {
	while (scanf("%d%d", &h, &k) && (h || k)) {
		max = 0;
		int use[10] = {};
		find(0, use, 0);
		for (int i = 0; i < k; ++ i) {
			printf("%3d", ans[i]);
		}
		printf(" ->%3d\n", max);
	}
	return 0;
}
