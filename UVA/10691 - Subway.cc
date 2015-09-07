#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200 + 10;
const double Pi = acos(-1.0);

struct Node {
	double l, r;
	bool operator < (const Node &rhs) const {
		if (r == rhs.r) return l > rhs.l;
		else return r < rhs.r;
	}
} A[MAXN * 2];

int N, M;

inline int solve() {
	sort(A, A + M);
	for (int i = 0; i < M; ++ i) {
		A[i + M].l = A[i].l + 2 * Pi;
		A[i + M].r = A[i].r + 2 * Pi;
	}
	int ret = M;
	for (int i = 0; i < M; ++ i) {
		int tmp = 1; double v = A[i].r;
		for (int j = i + 1; j < i + M; ++ j) {
			if (v - A[j].l < -1e-9) tmp ++, v = A[j].r;
		}
		if (tmp < ret) ret = tmp;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		double d, x, y; M = 0;
		scanf("%d%lf", &N, &d);
		for (int i = 0; i < N; ++ i) {
			scanf("%lf%lf", &x, &y);
			if (hypot(x, y) > d) {
				double p = atan2(y, x);
				double da = asin(d / hypot(x, y));
				A[M].l = p - da; A[M ++].r = p + da;
				if (A[M - 1].r > Pi) {
					A[M - 1].l -= 2 * Pi;
					A[M - 1].r -= 2 * Pi;
				}
			}
		}
		printf("%d\n", solve());
	}
	return 0;
}
