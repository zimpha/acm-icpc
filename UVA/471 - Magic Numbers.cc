#include <stdio.h>
#include <string.h>

typedef long long ll;
const ll INF = 9876543210ll;

bool judge(ll c) {
	int v[15];
	memset(v, 0, sizeof(v));
	while (c) {
		int t = c % 10;
		if (v[t]) return false;
		v[t] ++;
		c /= 10;
	}
	return true;
}

int main () {
	int cas;
	ll n, ans;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%lld", &n);
		for (ll i = 1; i <= INF; ++ i) {
			ans = i * n;
			if (ans > INF) break;
			if (judge(ans) && judge(i))
				printf("%lld / %lld = %lld\n", ans, i, n);
		}
		if (cas) printf("\n");
	}
	return 0;
}

