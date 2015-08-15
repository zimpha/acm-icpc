#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, k, cost[20], weight[20];
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d", &cost[i], &weight[i]);
		}
		int ret = 0;
		for (int mask = 0; mask < (1 << n); ++ mask) {
			int sumc = 0, sumw = 0;
			for (int i = 0; i < n; ++ i) {
				if ((mask >> i) & 1) sumc += cost[i], sumw += weight[i];
			}
			if (sumc <= k) ret = max(ret, sumw);
		}
		printf("%d\n", ret);
	}
	return 0;
}
