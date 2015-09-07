#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

double r[10], p[10];
int a[10];

int main() {
	int T, N; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%lf", &r[i]), a[i] = i;
		double ret = 1e9;
		do {
			double L = 0, R = 0;
			p[0] = 0;
			for (int i = 1; i < N; ++ i) {
				p[i] = 0;
				for (int j = 0; j < i; ++ j)
					p[i] = max(p[i], p[j] + 2.0 * sqrt(r[a[i]] * r[a[j]]));
			}
			for (int i = 0; i < N; ++ i) L = min(L, p[i] - r[a[i]]), R = max(R, p[i] + r[a[i]]);
			ret = min(ret, R - L);
		} while (next_permutation(a, a + N));
		printf("%.3f\n", ret);
	}
	return 0;
}
