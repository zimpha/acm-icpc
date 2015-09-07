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

int A[MAXN], Tr[MAXN << 2];
int N, Q;

void build(int rt, int l, int r) {
	if (l == r) {
		scanf("%d", &A[l]);
		Tr[rt] = A[l];
		return;
	}
	build(lson, l, mid); build(rson, mid + 1, r);
	Tr[rt] = min(Tr[lson], Tr[rson]);
}

void Modify(int rt, int l, int r, int x, int v) {
	if (l == r) {
		Tr[rt] = v;
		return;
	}
	if (x <= mid) Modify(lson, l, mid, x, v);
	else Modify(rson, mid + 1, r, x, v);
	Tr[rt] = min(Tr[lson], Tr[rson]);
}

int Query(int rt, int l, int r, int L, int R) {
	if (L <= l && R >= r) return Tr[rt];
	int ret = 1000000;
	if (L <= mid) ret = min(ret, Query(lson, l, mid, L, R));
	if (R > mid) ret = min(ret, Query(rson, mid + 1, r, L, R));
	return ret;
}

void query(char st[]) {
	int l, r;
	sscanf(st, "query(%d,%d)", &l, &r);
	printf("%d\n", Query(1, 1, N, l, r));
}

void shift(char st[]) {
	vector <int> p; p.clear();
	int K = 0;
	for (int i = 5, x; st[i] != ')'; ++ i) {
		if (st[i] == '(' || st[i] == ',') {
			sscanf(st + i + 1, "%d", &x);
			p.push_back(x);
			K ++;
		}
	}
	int tmp = A[p[0]];
	for (int i = 1; i < K; ++ i) A[p[i - 1]] = A[p[i]];
	A[p[K - 1]] = tmp;
	for (int i = 0; i < K; ++ i) Modify(1, 1, N, p[i], A[p[i]]);
}

int main() {
	scanf("%d%d", &N, &Q);
	build(1, 1, N);
	while (Q --) {
		char st[100]; scanf("%s", st);
		if (st[0] == 'q') query(st);
		else shift(st);
	}
	return 0;
}
