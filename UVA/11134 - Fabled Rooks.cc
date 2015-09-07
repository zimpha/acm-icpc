#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 5000 + 10;

struct Node {
	int l, r, id;
};

Node X[MAXN], Y[MAXN];
int retX[MAXN], retY[MAXN];
int N;

bool solve(int N, Node A[], int ret[]) {
	memset(ret, -1, sizeof(ret[0]) * N);
	for (int i = 1; i <= N; ++ i) {
		int mx = -1;
		for (int j = 0; j < N; ++ j) {
			if (ret[A[j].id] == -1 && A[j].l <= i && A[j].r >= i) {
				if (mx == -1 || A[j].r < A[mx].r) mx = j;
			}
		}
		if (mx == -1) return false;
		ret[A[mx].id] = i;
	}
	return true;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) {
			scanf("%d%d%d%d", &X[i].l, &Y[i].l, &X[i].r, &Y[i].r);
			X[i].id = Y[i].id = i;
		}
		if (solve(N, X, retX) && solve(N, Y, retY)) {
			for (int i = 0; i < N; ++ i) printf("%d %d\n", retX[i], retY[i]);
		} else puts("IMPOSSIBLE");
	}
	return 0;
}
