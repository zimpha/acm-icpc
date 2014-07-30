#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAXN = 200000 + 10;

int dp[MAXN];
int N, Q;

int main() {
	while (scanf("%d%d", &N, &Q) == 2) {
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++ i) {
			int x; scanf("%d", &x);
			dp[x] ++;
		}
		while (Q --) {
			int l, r, c; scanf("%d%d%d", &l, &r, &c);	
			for (int i = r; i >= l; -- i) {
				dp[i + c] += dp[i];
				dp[i] = 0;
			}
		}
		LL ret = 0;
		for (int i = 0; i < MAXN; ++ i) ret += (LL)i * dp[i];
		printf("%lld\n", ret);
	}
	return 0;
}
