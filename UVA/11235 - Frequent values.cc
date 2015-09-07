#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN=100005;

struct node {
	int lc, rc, mc;
};

node tree[MAXN << 2];
int A[MAXN];
int N, M;

inline void update(int rt, int l, int r) {
	tree[rt].mc = max(tree[lson].mc, tree[rson].mc);
	tree[rt].lc = tree[lson].lc; tree[rt].rc = tree[rson].rc;
	if (A[mid] == A[mid + 1]) {
		tree[rt].mc = max(tree[rt].mc, tree[lson].rc + tree[rson].lc);
		if (A[l] == A[mid]) tree[rt].lc += tree[rson].lc;
		if (A[r] == A[mid + 1]) tree[rt].rc += tree[lson].rc;
	}
}

void build(int rt, int l, int r) {
	if (l == r) {
		scanf("%d", &A[l]);
		tree[rt].lc = tree[rt].rc = tree[rt].mc = 1;
		return;
	}
	build(lson, l, mid); build(rson, mid + 1, r);
	update(rt, l, r);
}

int query(int rt, int l, int r, int ll, int rr) {
	if (ll == l && rr == r) return tree[rt].mc;
	if (rr <= mid) return query(lson, l, mid, ll, rr);
	if (ll > mid) return query(rson, mid + 1, r, ll, rr);
	int ans1 = query(lson, l, mid, ll, mid);
	int ans2 = query(rson, mid+1, r, mid+1, rr);
	int ret = max(ans1, ans2);
	if (A[mid] == A[mid + 1]) {
		ret = max(ret, min(mid - ll + 1, tree[lson].rc) + min(rr - mid, tree[rson].lc));
	}
	return ret;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		build(1, 1, N);
		while (M--) {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", query(1, 1, N, l, r));
		}
	}
	return 0;
}
