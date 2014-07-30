#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char N[20];
int dp[20][2];

int solve(int d, int e) {
	if (d == 11) return 1;
	if (dp[d][e] != -1) return dp[d][e];
	int t = e ? 9 : (N[d] - '0');
	int ret = 0;
	for (int i = 0; i <= t; ++ i) {
		if (i == 0) ret = max(ret, solve(d + 1, e | (i < t)));
		else ret = max(ret, i * solve(d + 1, e | (i < t)));
	}
	return dp[d][e] = ret;
}

int main() {
	freopen("m.in", "r", stdin);
	int n; scanf("%d", &n);
	sprintf(N, "%011d", n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve(0, 0));
	fclose(stdin); return 0;
}
