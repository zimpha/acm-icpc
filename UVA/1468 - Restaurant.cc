#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 60000 + 10;

int x[MAXN], y[MAXN], d[MAXN];
int N, M;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &M, &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d", x + i, y + i);
		int st = min(x[0], x[1]), ed = max(x[0], x[1]);
		for (int i = 0; i < M; ++ i) d[i] = M;
		for (int i = 0; i < N; ++ i) d[x[i]] = min(d[x[i]], abs(y[i] - y[0]));
		for (int i = st + 1; i < ed; ++ i) d[i] = min(d[i], d[i - 1] + 1);
		for (int i = ed - 1; i > st; -- i) d[i] = min(d[i], d[i + 1] + 1);
		long long ret = 0;
		for (int i = st + 1; i < ed; ++ i) {
			if (!d[i]) continue;
			ret += min(d[i] - 1, y[0]) + min(d[i], M - y[0]);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
