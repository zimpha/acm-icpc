#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN = 100000 + 10;

struct Node {
	int ml, mr, mm;
	int l, r;
};

Node T[MAXN << 2];
int A[MAXN];
inline void update(int rt) {
	T[rt].mm = max(T[lson].mm, T[rson].mm);
	T[rt].ml = T[lson].ml; T[rt].mr = T[rson].mr;
	if (A[T[lson].r] + 1 == A[T[rson].l]) {
		T[rt].mm = max(T[rt].mm, T[lson].mr + T[rson].ml);
		if (T[lson].ml == T[lson].r - T[lson].l + 1) 
			T[rt].ml += T[rson].ml;
		if (T[rson].mr == T[rson].r - T[rson].l + 1)
			T[rt].mr += T[lson].mr;
	}
}

void build(int rt, int l, int r) {
	T[rt].l = l; T[rt].r = r;
	T[rt].ml = T[rt].mr = T[rt].mm = 1;
	if (l == r) {
		scanf("%d", &A[l]);
		return;
	}
	build(lson, l, mid);
	build(rson, mid + 1, r);
	update(rt);
}

void Modify(int rt, int l, int r, int p, int v) {
	if (l == r) {
		A[p] = v;
		return ;
	}
	if (p <= mid) Modify(lson, l, mid, p, v);
	else Modify(rson, mid + 1, r, p, v);
	update(rt);
}

int main() {
	int N, M; 
	scanf("%d%d", &N, &M);
	build(1, 1, N);
	printf("%d\n", T[1].mm);
	for (int i = 0; i < M; ++ i) {
		int x, y; scanf("%d%d", &x, &y);
		Modify(1, 1, N, x, y);
		printf("%d\n", T[1].mm);
	}
	return 0;
}
