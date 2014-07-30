#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int n, a;
		long long best, worst;
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%d", &a);
			if (i) {
				if (a > 0) {
					best = max(best + a, max(best - a, best * a));
					worst = min(worst - a, min(worst * a, worst - a));
				}
				else {
					long long tb = best, tw = worst;
					best = max(best + a, max(best - a, tw * a));
					worst = min(worst - a, min(worst + a, tb * a));
				}
			}
			else best = worst = a;
		}
		printf("%lld\n", worst);
	}
	return 0;
}
