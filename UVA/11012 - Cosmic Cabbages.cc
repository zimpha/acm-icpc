#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int inf = 1e9;
const int MAXN = 100000 + 10;

int p[MAXN][3], N;

inline int sgn(int x) {
	return x ? 1 : -1;
}

int main() {
	int T; scanf("%d", &T);	
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d%d", &p[i][0], &p[i][1], &p[i][2]);
		int ret = 0;
		for (int mask = 0; mask < 8; ++ mask) {
			int Max = -inf, Min = inf;
			for (int i = 0; i < N; ++ i) {
				int tmp = p[i][0] * sgn(mask & 1) + p[i][1] * sgn(mask & 2) + p[i][2] * sgn(mask & 4);
				Max = max(Max, tmp);
				Min = min(Min, tmp);
			}
			ret = max(ret, Max - Min);
		}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}
