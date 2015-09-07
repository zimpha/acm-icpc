#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN = 200000 + 10;

int Tr[MAXN << 2], A[MAXN], B[MAXN];
int L[MAXN], R[MAXN];
int N, M;

void build(int rt, int l, int r) {
	Tr[rt] = 0;
	if (l == r) return;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}

void Modify(int rt, int l, int r, int p, int v) {
	if (l == r) {
		Tr[rt] = max(Tr[rt], v);
		return;
	}
	if (p <= mid) Modify(lson, l, mid, p, v);
	else Modify(rson, mid + 1, r, p, v);
	Tr[rt] = max(Tr[lson], Tr[rson]);
}

int Query(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) return Tr[rt];
	int ret = 0;
	if (L <= mid) ret = max(ret, Query(lson, l, mid, L, R));
	if (R > mid) ret = max(ret, Query(rson, mid + 1, r, L, R));
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &A[i]);
			B[i] = A[i];
		}
		sort(B, B + N);
		M = 1;
		for (int i = 1; i < N; ++ i) {
			if (B[i] != B[i - 1]) B[M ++] = B[i];
		}
		for (int i = 0; i < N; ++ i) {
			A[i] = lower_bound(B, B + M, A[i]) - B + 1;
		}
		L[0] = 1; R[N - 1] = 1;
		for (int i = 1; i < N; ++ i) {
			if (A[i] > A[i - 1]) L[i] = L[i - 1] + 1;
			else L[i] = 1;
		}
		for (int i = N - 2; i >= 0; -- i) {
			if (A[i] < A[i + 1]) R[i] = R[i + 1] + 1;
			else R[i] = 1;
		}
		build(1, 0, M);
		int ret = 0;
		for (int i = 0; i < N; ++ i) {
			int tmp = Query(1, 0, M, 0, A[i] - 1) + R[i];
			ret = max(ret, tmp);
			Modify(1, 0, M, A[i], L[i]);
		}
		printf("%d\n", ret);
	}
	return 0;
}
