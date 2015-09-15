#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000000 + 10;
int cnt[MAXN], n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) {
		int x;
		scanf("%d", &x), cnt[x] ++;
	}
	LL ret = 0;
	for (int i = 1; i < MAXN; ++ i) {
		ret += (LL)cnt[i] * (cnt[i] - 1);
		if (!cnt[i]) continue;
		for (int j = i + i; j < MAXN; j += i) {
			ret += (LL)cnt[i] * cnt[j];
		}
	}
	printf("%lld\n", ret);
	return 0;
}
