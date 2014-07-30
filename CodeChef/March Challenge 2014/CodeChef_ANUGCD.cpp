#include <vector>
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
	int mx, cnt;
	Node() {}
	Node(int m, int c) : mx(m), cnt(c) {}
};

int A[MAXN], P[MAXN];

struct SegTree {
	vector<int> pos;
	vector<Node> T;
	SegTree() {
		pos.clear(); T.clear();
	}
	void insert(int x) {
		pos.push_back(x);
	}
	void update(int rt) {
		T[rt].mx = max(T[lson].mx, T[rson].mx); T[rt].cnt = 0;
		if (T[rt].mx == T[lson].mx) T[rt].cnt += T[lson].cnt;
		if (T[rt].mx == T[rson].mx) T[rt].cnt += T[rson].cnt;
	}
	void build(int rt, int l, int r) {
		if (l + 1 == r) {
			T[rt].mx = A[pos[l]];
			T[rt].cnt = 1;
			return;
		}
		build(lson, l, mid);
		build(rson, mid, r);
		update(rt);
	}
	void build() {
		T.resize(pos.size() << 2);
		if (!pos.size()) return;
		build(1, 0, pos.size());
	}
	Node query(int rt, int l, int r, int L, int R) {
		if (L >= R) return Node(0, 0);
		if (L <= l && R >= r) return T[rt];
		Node ret = Node(0, 0), ls = Node(0, 0), rs = Node(0, 0);
		if (L < mid) ls = query(lson, l, mid, L, R);
		if (R > mid) rs = query(rson, mid, r, L, R);
		ret.mx = max(ls.mx, rs.mx);
		if (ret.mx == ls.mx) ret.cnt += ls.cnt;
		if (ret.mx == rs.mx) ret.cnt += rs.cnt;
		return ret;
	}
	Node query(int x, int y) {
		int l = lower_bound(pos.begin(), pos.end(), x) - pos.begin();	
		int r = upper_bound(pos.begin(), pos.end(), y) - pos.begin();	
		return query(1, 0, pos.size(), l, r);
	}
};

SegTree T[MAXN];
int N, M, Q;

void sieve() {
	memset(P, 0, sizeof(P)); M = 0;
	for (int i = 2; i < MAXN; ++ i) {
		if (!P[i]) {
			P[M ++] = i;
			for (int j = i + i; j < MAXN; j += i) P[j] = 1;
		}
	}
}

void factorial(int pos, int x) {
	vector<int> factor;
	for (int i = 2; i * i <= x; ++ i) {
		if (x % i == 0) {
			factor.push_back(i);
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) factor.push_back(x);
	for (int i = 0; i < (int)factor.size(); ++ i) {
		int idx = lower_bound(P, P + M, factor[i]) - P;
		T[idx].insert(pos);
	}
}

Node solve(int prime, int x, int y) {
	int idx = lower_bound(P, P + M, prime) - P;
	return T[idx].query(x, y);
}

int main() {
	sieve();
	scanf("%d%d", &N, &Q);
	for (int i = 0; i < N; ++ i) {
		scanf("%d", &A[i]);
		factorial(i, A[i]);
	}
	for (int i = 0; i < M; ++ i) T[i].build();
	while (Q --) {
		int G, x, y; scanf("%d%d%d", &G, &x, &y);
		x --, y --;
		Node ret = Node(0, 0), tmp;
		for (int i = 2; i * i <= G; ++ i) {
			if (G % i == 0) {
				tmp = solve(i, x, y);
				if (tmp.mx > ret.mx) ret = tmp;
				while (G % i == 0) G /= i;
			}
		}
		if (G > 1) {
			tmp = solve(G, x, y);
			if (tmp.mx > ret.mx) ret = tmp;
		}
		if (ret.mx == 0) puts("-1 -1");
		else printf("%d %d\n", ret.mx, ret.cnt);
	}
	return 0;
}
