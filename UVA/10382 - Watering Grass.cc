#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 10000 + 10;

struct Node {
	double l, r;
	bool operator < (const Node &rhs) const {
		return l < rhs.l;
	}
};

Node A[MAXN];
int N, L, W;

int main() {
	while (scanf("%d%d%d", &N, &L, &W) == 3) {
		int M = 0;
		for (int i = 0; i < N; ++ i) {
			double p, r; scanf("%lf%lf", &p, &r);
			if (W >= 2.0 * r) continue;
			double d = sqrt(r * r - W * W / 4.0);
			A[M].l = p - d; A[M].r = p + d; M ++;
		}
		N = M; sort(A, A + N);
		int ret = 0, flag = 0;
		if (A[0].l <= 0) {
			double l = 0, r = 0;
			for (int i = 0, j; i < N; i = j) {
				for (j = i; j < N && l >= A[j].l; j ++) {
					if (A[j].r > r) r = A[j].r;
				}
				if (j == i) break;
				ret ++; l = r;
				if (l >= L) {
					flag = 1;
					break;
				}
			}
		}
		if (flag) printf("%d\n", ret);
		else puts("-1");
	}
	return 0;
}
