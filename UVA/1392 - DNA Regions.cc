#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;
const int MAXN = 150000 + 10;

char s1[MAXN], s2[MAXN];
int A[MAXN], B[MAXN];
int T[MAXN << 2];

void build(int rt, int l, int r) {
	T[rt] = MAXN;
	if (l == r) return;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}

void Modify(int rt, int l, int r, int p, int v) {
	if (l == r) {
		T[rt] = min(T[rt], v);
		return;
	}
	if (p <= mid) Modify(lson, l, mid, p, v);
	else Modify(rson, mid + 1, r, p, v);
	T[rt] = min(T[lson], T[rson]);
}

int Query(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) return T[rt];
	int ret = MAXN;
	if (L <= mid) ret = min(ret, Query(lson, l, mid, L, R));
	if (R > mid) ret = min(ret, Query(rson, mid + 1, r, L, R));
	return ret;
}

int main() {
	int N, P;
	while (scanf("%d%d", &N, &P) == 2 && N) {
		scanf("%s%s", s1 + 1, s2 + 1);
		B[0] = A[0] = 0;
		for (int i = 1; i <= N; ++ i) {
			A[i] = A[i - 1] + (s1[i] != s2[i]);
		}
		for (int i = 1; i <= N; ++ i) {
			B[i] = A[i] = 100 * A[i] - P * i;
		}
		sort(B, B + 1 + N);
		int M = unique(B, B + 1 + N) - B;
		for (int i = 0; i <= N; ++ i) A[i] = lower_bound(B, B + M, A[i]) - B + 1;
		build(1, 1, M);
		int ret = -1;
		for (int i = 0; i <= N; ++ i) {
			int t = Query(1, 1, M, A[i], M);
			if (t < MAXN && i - t > ret) ret = i - t;
			Modify(1, 1, M, A[i], i);
		}
		if (ret == -1) puts("No solution.");
		else printf("%d\n", ret);
	}
	return 0;
}
