#include <bits/stdc++.h>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

const int MAXN = 100000 + 10;

set<int> Position[MAXN];
vector<int> PrimeFactor[MAXN], Prime;
int Cover[MAXN << 2], Sum[MAXN << 2];
int IsPrime[MAXN], A[MAXN], N, K, M;
int LastPrime[MAXN], ina[MAXN], inb[MAXN];

void prepare() {
	Prime.clear();
	for (int i = 0; i < MAXN; ++ i) PrimeFactor[i].clear(), IsPrime[i] = true;
	IsPrime[0] = IsPrime[1] = false;
	for (int i = 2; i < MAXN; ++ i) {
		if (IsPrime[i]) {
			for (int j = i; j < MAXN; j += i) {
				PrimeFactor[j].push_back(Prime.size());
				if (j != i) IsPrime[j] = false;
			}
			Prime.push_back(i);
		}
	}
}

void Modify(int rt, int l, int r, int L, int R, int D) { // [l, r) [L, R)
	if (L <= l && R >= r) Cover[rt] += D;
	else {
		if (L < mid) Modify(lson, l, mid, L, R, D);
		if (R > mid) Modify(rson, mid, r, L, R, D);
	}
	if (Cover[rt] > 0) Sum[rt] = r - l;
	else if (l + 1 == r) Sum[rt] = 0;
	else Sum[rt] = Sum[lson] + Sum[rson];
}

typedef set<int>::iterator Iter;

void Erase(int idx) {
	vector<int> &Factor = PrimeFactor[A[idx]];
	for (auto p : Factor) {
		set<int> &S = Position[p];
		Iter it = S.find(idx), pre, next;
		if (it != S.begin()) {
			-- it; pre = it; ++ it;
			if (idx - *pre < K) {
				int l = max(idx, K - 1), r = min(*pre + K, N);
				Modify(1, 0, N, l, r, -1);
			}
		}
		++ it; next = it; -- it;
		if (next != S.end()) {
			if (*next - idx < K) {
				int l = max(*next, K - 1), r = min(idx + K, N);
				Modify(1, 0, N, l, r, -1);
			}
			if (it != S.begin()) {
				if (*next - *pre < K) {
					int l = max(*next, K - 1), r = min(*pre + K, N);
					Modify(1, 0, N, l, r, 1);
				}
			}
		}
		S.erase(idx);
	}
}

void Insert(int idx, int value) {
	A[idx] = value;
	vector<int> &Factor = PrimeFactor[A[idx]];
	for (auto p : Factor) {
		set<int> &S = Position[p]; S.insert(idx);
		Iter it = S.find(idx), pre, next;
		if (it != S.begin()) {
			-- it; pre = it; ++ it;
			if (idx - *pre < K) {
				int l = max(idx, K - 1), r = min(*pre + K, N);
				Modify(1, 0, N, l, r, 1);
			}
		}
		++ it; next = it; -- it;
		if (next != S.end()) {
			if (*next - idx < K) {
				int l = max(*next, K - 1), r = min(idx + K, N);
				Modify(1, 0, N, l, r, 1);
			}
			if (it != S.begin()) {
				if (*next - *pre < K) {
					int l = max(*next, K - 1), r = min(*pre + K, N);
					Modify(1, 0, N, l, r, -1);
				}
			}
		}
	}
}

int main() {
	prepare();
	while (scanf("%d%d%d", &N, &K, &M) == 3 && N) {
		memset(Cover, 0, sizeof(Cover));
		memset(Sum, 0, sizeof(Sum));
		for (int i = 0; i < (int)Prime.size(); ++ i) LastPrime[i] = -1, Position[i].clear();
		long long total = 0;
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &A[i]); total += A[i];
			vector<int> &Factor = PrimeFactor[A[i]];
			for (auto p : Factor) {
				if (LastPrime[p] >= 0 && i - LastPrime[p] < K) {
					int L = max(i, K - 1), R = min(LastPrime[p] + K, N);
					Modify(1, 0, N, L, R, 1);
				}
				Position[p].insert(i);
				LastPrime[p] = i;
			}
		}
		printf("%d\n", Sum[1]);
		while (M --) {
			int a, b; scanf("%d%d", &a, &b); -- a;
			total += b - A[a];
			Erase(a);
			Insert(a, b);
			printf("%d\n", Sum[1]);
		}
		printf("%lld\n", total);
	}
	return 0;
}
