#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)
using namespace std;
const int MAXN = 200000 + 10;

int Tr[MAXN << 2];
int N;

void build(int rt, int l, int r) {
	if (l == r) {
		scanf("%d", &Tr[rt]);
		return;
	}
	build(lson, l, mid);
	build(rson, mid + 1, r);
	Tr[rt] = Tr[lson] + Tr[rson];
}

void Modify(int rt, int l, int r, int x, int v) {
	if (l == r) {
		Tr[rt] = v;
		return;
	}
	if (x <= mid) Modify(lson, l, mid, x, v);
	else Modify(rson, mid + 1, r, x, v);
	Tr[rt] = Tr[lson] + Tr[rson];
}

int Query(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) return Tr[rt];
	int ret = 0;
	if (L <= mid) ret += Query(lson, l, mid, L, R);
	if (R > mid) ret += Query(rson, mid + 1, r, L, R);
	return ret;
}

int main() {
	int cas = 0;
	while (scanf("%d", &N) == 1 && N) {
		build(1, 1, N);
		char st[10];
		int x, y;
		if (cas) puts("");
		printf("Case %d:\n", ++ cas);
		while (scanf("%s", st) == 1 && st[0] != 'E') {
			scanf("%d%d", &x, &y);
			if (st[0] == 'S') Modify(1, 1, N, x, y);
			else printf("%d\n", Query(1, 1, N, x, y));
		}
	}
	return 0;
}
