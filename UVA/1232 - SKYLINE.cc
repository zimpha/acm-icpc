#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN = 100000 + 10;

struct Node {
	int mi, ma;
	int set;
	void Set(int x) {
		mi = ma = set = x;
	}
};

Node Tr[MAXN << 2];

void build(int rt, int l, int r) {
	Tr[rt].mi = Tr[rt].ma = 0;
	Tr[rt].set = -1;
	if (l + 1 == r) return;
	build(lson, l, mid);
	build(rson, mid, r);
}

inline void PushDown(int rt) {
	if (Tr[rt].set != -1) {
		Tr[lson].Set(Tr[rt].set);
		Tr[rson].Set(Tr[rt].set);
		Tr[rt].set = -1;
	}
}

inline void Update(int rt) {
	Tr[rt].ma = max(Tr[lson].ma, Tr[rson].ma);
	Tr[rt].mi = min(Tr[lson].mi, Tr[rson].mi);
}

int Cover(int rt, int l, int r, int L, int R, int v) {
	if (Tr[rt].mi > v) return 0;
	if (L <= l && R >= r) {
		if (Tr[rt].ma <= v) {
			Tr[rt].Set(v);
			return r - l;
		}
	}
	PushDown(rt);
	int ret = 0;
	if (L < mid) ret += Cover(lson, l, mid, L, R, v);
	if (R > mid) ret += Cover(rson, mid, r, L, R, v);
	Update(rt); return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int N, l, r, h, ret = 0;
		build(1, 1, 100000);
		scanf("%d", &N);
		while (N --) {
			scanf("%d%d%d", &l, &r, &h);
			int x = Cover(1, 1, 100000, l, r, h);
			ret += x;
//			printf("%d\n", x);
		}
		printf("%d\n", ret);
	}
	return 0;
}
