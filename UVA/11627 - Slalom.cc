#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXS = 1000000 + 10;

int x[MAXN], y[MAXN];
int W, vh, N, S;

bool check(int vv) {
	if (vv == 0) return false;
	double l = x[0], r = x[0] + W;
	for (int i = 1; i < N; ++ i) {
		double dis = vh * (double)(y[i] - y[i - 1]) / vv;
		l = max(l - dis, (double)x[i]);
		r = min(r + dis, (double)x[i] + W);
		if (l > r + 1e-9) return false;
	}
	return true;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &W, &vh, &N);
//	while (scanf("%d%d%d", &W, &vh, &N) == 3) {
		for (int i = 0; i < N; ++ i) scanf("%d%d", &x[i], &y[i]);
		int left = 0, right = 1e6 + 10, ret = 0;
		while (left < right) {
			int mid = (left + right + 1) >> 1;
			if (check(mid)) left = mid;
			else right = mid - 1;
		}
		scanf("%d", &S);
		for (int i = 0, x; i < S; ++ i) {
			scanf("%d", &x);
			if (x <= left) ret = max(ret, x);
		}
		if (ret == 0) puts("IMPOSSIBLE");
		else printf("%d\n", ret);
	}
	return 0;
}
