#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;
const int inf = 1e9;

int ceiling[MAXN], floor[MAXN], N;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d", floor + i);
		for (int i = 0; i < N; ++ i) scanf("%d", ceiling + i);
		for (int i = N - 1, tmp = inf; i >= 0; -- i) {
			tmp = min(tmp, ceiling[i]);
			tmp = max(tmp, floor[i]);
			ceiling[i] = tmp;
		}
		int ret = 0;
		for (int i = 0, tmp = inf; i < N; ++ i) {
			tmp = max(tmp, floor[i]);
			tmp = min(tmp, ceiling[i]);
			ceiling[i] = tmp;
			ret += ceiling[i] - floor[i];
		}
		printf("%d\n", ret);
	}
	return 0;
}
