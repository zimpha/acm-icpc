#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

struct Node {
	int L, R, P, H;
} A[MAXN];

int height[MAXN];
int N, root;

void build(int X) {
	if (X == 0) return;
	build(A[X].L); build(A[X].R);
	A[X].H = max(A[A[X].L].H, A[A[X].R].H) + 1;
}

void solve(int X, int lh = 0, int rh = 0, int lth = 0, int rth = 0) {
	if (X == 0) return;
	int LH = A[A[X].L].H, RH = A[A[X].R].H;
	height[X] = max(max(lh, rh), max(lth + LH, rth + RH)) + 1;
	solve(A[X].L, lh, max(rh, 1 + rth + RH), lth, 1 + rth);
	solve(A[X].R, max(lh, 1 + lth + LH), rh, 1 + lth, rth);
}

int main() {
	A[0].L = A[0].R = A[0].P = A[0].H = 0;
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 1; i <= N; ++ i) A[i].P = 0;
		for (int i = 1; i <= N; ++ i) {
			int l, r; scanf("%d%d", &l, &r);
			A[i].L = l; if (l) A[l].P = i;
			A[i].R = r; if (r) A[r].P = i;
		}
		for (int i = 1; i <= N; ++ i) if (A[i].P == 0) root = i;
		build(root);
		solve(root);
		for (int i = 1; i <= N; ++ i) {
			printf("%d\n", height[i]);
		}
	}
	return 0;
}
