#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;

const int MAXN = 100000 + 10;
const int MAXM = 200000 + 10;
const LL inf = 1ll<<60;

LL S[MAXN], ret[MAXM];
int N, M, T;

struct SegTree {
	vector<LL> T;
	int n;
	void build(int rt, int l, int r) {
		T[rt] = inf;
		if (l + 1 == r) return;
		build(lson, l, mid); build(rson, mid, r);
	}
	void init(int N) {
		this->n = N;
		T.resize(N << 2);
		build(1, 0, N);
	}
	void Modify(int rt, int l, int r, int p, LL v) {
		if (l + 1 == r) {
			T[rt] = min(T[rt], v);
			return;
		}
		if (p < mid) Modify(lson, l, mid, p, v);
		else Modify(rson, mid, r, p, v);
		T[rt] = min(T[lson], T[rson]);
	}
	void add(int i, int j, LL w, bool F) {
		if (F) Modify(1, 0, n, i - 1, w + S[i] - S[j]);
		else Modify(1, 0, n, j - 1, w + S[i] - S[j]);
	}
	LL query(int rt, int l, int r, int L, int R) {
		if (L <= l && R >= r) return T[rt];
		LL ret = inf;
		if (L < mid) ret = min(ret, query(lson, l, mid, L, R));
		if (R > mid) ret = min(ret, query(rson, mid, r, L, R));
		return ret;
	}
	LL query(int u, int v) {
		u --; v --;
		return query(1, 0, n, u, v);
	}
} Tree;

struct Node {
	int u, v, w;
};

Node Query[MAXM], edge[MAXM];

inline bool cmpu(const Node &a, const Node &b) {
	if (a.u != b.u) return a.u > b.u;
	return a.v > b.v;
}

inline bool cmpv(const Node &a, const Node &b) {
	if (a.v != b.v) return a.v < b.v;
	return a.u < b.u;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2) {
		S[1] = 0;
		for (int i = 2; i <= N; ++ i) {
			scanf("%lld", &S[i]);
			S[i] += S[i - 1];
		}
		for (int i = 0; i < M; ++ i) {
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		}
		scanf("%d", &T);
		for (int i = 0; i < T; ++ i) {
			scanf("%d%d", &Query[i].u, &Query[i].v);
			Query[i].w = i;
		}
		sort(edge, edge + M, cmpv);
		sort(Query, Query + T, cmpv);
		Tree.init(N);
		memset(ret, 0, sizeof(ret));
		for (int i = 0, j = 0; i < T; ++ i) {
			int u = Query[i].u, v = Query[i].v, idx = Query[i].w;
			if (u < v) {
				for (; j < M && edge[j].v <= v; ++ j) {
					if (edge[j].u >= edge[j].v) continue;
					Tree.add(edge[j].u, edge[j].v, edge[j].w, 1);
				}
				ret[idx] = S[v] - S[u] + min(0ll, Tree.query(u, v));
				assert(ret[idx] < 1ll << 32ll);
			}
		}
		sort(edge, edge + M, cmpu);
		sort(Query, Query + T, cmpu);
		Tree.init(N);
		for (int i = 0, j = 0; i < T; ++ i) {
			int u = Query[i].u, v = Query[i].v, idx = Query[i].w;
			if (u > v) {
				for (; j < M && edge[j].u >= u; ++ j) {
					if (edge[j].u <= edge[j].v) continue;
					Tree.add(edge[j].u, edge[j].v, edge[j].w, 0);
				}
				ret[idx] = S[v] - S[u] + Tree.query(1, v + 1);
			}
		}
		for (int i = 0; i < T; ++ i) {
			printf("%lld\n", ret[i]);
		}
	}
	return 0;
}
