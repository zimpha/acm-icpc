#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)

using namespace std;
const int inf = 1000000000;
typedef vector <int> VI;
struct node {
	int sum, ma, mi;
	int add, set;
	int l, r;
	void Add(int x) {
		if (set) Set(set +x);
		else {
			sum += x * (r - l + 1);
			ma += x; mi += x;
			add += x;
		}
	}
	void Set(int x) {
		sum = x * (r - l + 1);
		ma = mi = set = x;
		if (add) add = 0;
	}
};

struct Tree {
	vector <node> T;
	int n;

	void init(int n) {
		this->n = n;
		T.resize(n << 2);
		build(1, 1, n);
	}
	void build(int rt, int l, int r) {
		T[rt].sum = T[rt].ma = T[rt].mi = T[rt].add = T[rt].set = 0;
		T[rt].l = l; T[rt].r = r;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(lson, l, mid); build(rson, mid + 1, r);
	}
	void PushDown(int rt) {
		if (T[rt].set) {
			T[lson].Set(T[rt].set);
			T[rson].Set(T[rt].set);
		}
		if (T[rt].add) {
			T[lson].Add(T[rt].add);
			T[rson].Add(T[rt].add);
		}
		T[rt].set = T[rt].add = 0;
	}
	void Update(int rt) {
		T[rt].sum = T[lson].sum + T[rson].sum;
		T[rt].ma = max(T[lson].ma, T[rson].ma);
		T[rt].mi = min(T[lson].mi, T[rson].mi);
	}
	void Modify(int rt, int L, int R, int v, int t) {
		if (L <= T[rt].l && R >= T[rt].r) {
			if (t) T[rt].Set(v);
			else T[rt].Add(v);
			return;
		}
		PushDown(rt);
		int mid = (T[rt].l + T[rt].r) >> 1;
		if (L <= mid) Modify(lson, L, R, v, t);
		if (R > mid) Modify(rson, L, R, v, t);
		Update(rt);
	}
	VI Query(int rt, int L, int R) {
		VI ret(3), tmp(3);
		if (L <= T[rt].l && R >= T[rt].r) {
			ret[0] = T[rt].sum;
			ret[1] = T[rt].mi;
			ret[2] = T[rt].ma;
			return ret;
		}
		PushDown(rt);
		ret[0] = ret[2] = 0; ret[1] = inf;
		int mid = (T[rt].l + T[rt].r) >> 1;
		if (L <= mid) {
			tmp = Query(lson, L, R);
			ret[0] += tmp[0]; ret[1] = min(ret[1], tmp[1]); ret[2] = max(ret[2], tmp[2]);
		}
		if (R > mid) {
			tmp = Query(rson, L, R);
			ret[0] += tmp[0]; ret[1] = min(ret[1], tmp[1]); ret[2] = max(ret[2], tmp[2]);
		}
		return ret;
	}
};

vector <Tree> Matrix;

int main() {
	int R, C, M;
	while (scanf("%d%d%d", &R, &C, &M) == 3) {
		Matrix.resize(R);
		for (int i = 0; i < R; ++ i) Matrix[i].init(C);
		while (M --) {
			int op, x1, x2, y1, y2, v;
			scanf("%d%d%d%d%d", &op, &x1, &y1, &x2, &y2);
			if (op == 3) {
				VI ret(3), tmp;
				ret[0] = ret[2] = 0; ret[1] = inf;
				for (int i = x1; i <= x2; ++ i) {
					tmp = Matrix[i - 1].Query(1, y1, y2);
					ret[0] += tmp[0]; ret[1] = min(ret[1], tmp[1]); ret[2] = max(ret[2], tmp[2]);
				}
				printf("%d %d %d\n", ret[0], ret[1], ret[2]);
			} else {
				scanf("%d", &v);
				for (int i = x1; i <= x2; ++ i) {
					if (op == 1) Matrix[i - 1].Modify(1, y1, y2, v, 0);
					else Matrix[i - 1].Modify(1, y1, y2, v, 1);
				}
			}
		}
	}
	return 0;
}
