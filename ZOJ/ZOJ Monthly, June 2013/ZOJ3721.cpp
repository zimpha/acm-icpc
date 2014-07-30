#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

struct Node {
	int l, r, idx;
	bool operator < (const Node &rhs) const {
		if (l != rhs.l) return l < rhs.l;
		return r < rhs.r;
	}
};

Node A[MAXN];
int B[MAXN], N;

int main() {
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d", &A[i].l, &A[i].r);
			A[i].r --; A[i].idx = i + 1;
		}
		sort(A, A + N);
		int ret = 0;
		for (int i = 0, r = A[0].r; i < N; ++ i) {
			if (A[i].l > r) {
				ret ++; r = A[i].r;
				B[i] = ret;
			}
			else {
				B[i] = ret;
				r = min(r, A[i].r);
			}
		}
		printf("%d\n", ret + 1);
		for (int i = 0, j = 0; i <= ret; ++ i) {
			for (bool f = 0; j < N && B[j] == i; ++ j) {
				if (f) putchar(' ');
				else f = 1;
				printf("%d", A[j].idx);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
