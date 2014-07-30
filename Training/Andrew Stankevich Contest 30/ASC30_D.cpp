#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;

int pow[15];
char num[50];
LL dp[20][2][59049];

LL solve(int d, int e, int mask) {
	if (d == 20) return 1;
	if (dp[d][e][mask] != -1) return dp[d][e][mask];
	int t = e ? 9 : (num[d] - '0');
	LL ret = 0;
	for (int i = 0; i <= t; ++ i) {
		int used = mask / pow[i] % 3;
		if (used == 2) continue;
		int now = (mask / pow[i] + 1) * pow[i] + mask % pow[i];
		if (!mask && !i) now = 0;
		ret += solve(d + 1, e | (i < t), now);
	}
	return dp[d][e][mask] = ret;
}

LL calc(LL n) {
	sprintf(num, "%020I64d", n);
	memset(dp, -1, sizeof(dp));
	return solve(0, 0, 0);
}

int main() {
	freopen("exchange.in", "r", stdin);
	freopen("exchange.out", "w", stdout);
	LL l, r;
	scanf("%I64d%I64d", &l, &r);
	for (int i = 0; i < 15; ++ i) pow[i] = i ? pow[i - 1] * 3 : 1;
	printf("%I64d\n", calc(r) - calc(l - 1));
	fclose(stdin); fclose(stdout);
	return 0;
}
