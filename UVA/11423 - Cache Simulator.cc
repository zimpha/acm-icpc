#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int SIZE = 10000000 + 10;
const int MAXN = 30 + 10;

struct FenwickTree {
	int Tr[SIZE], N;
	void initial() {
		this->N = SIZE;
		memset(Tr, 0, sizeof(Tr));
	}
	void Update(int idx, int v) {
		for (int i = idx; i < N; i += i & -i) Tr[i] += v;
	}
	int rsq(int idx) {
		int ret = 0;
		for (int i = idx; i; i -= i & -i) ret += Tr[i];
		return ret;
	}
	int rsq(int a, int b) {
		return rsq(b) - rsq(a - 1);
	}
};

FenwickTree T;
int sz[MAXN], ret[MAXN], prev[1 << 24];
int N, Q;

void Access(int x) {
	if (prev[x]) {
		int cnt = T.rsq(prev[x], Q);
		for (int i = 0; i < N; ++ i) ret[i] += (cnt > sz[i]);
		T.Update(prev[x], -1);
	} else {
		for (int i = 0; i < N; ++ i) ret[i] ++;
	}
	prev[x] = ++ Q;
	T.Update(prev[x], 1);
}

int main() {
	scanf("%d", &N);	
	for (int i = 0; i < N; ++ i) scanf("%d", &sz[i]);
	char st[10];
	memset(ret, 0, sizeof(ret));
	memset(prev, 0, sizeof(prev));
	Q = 0; T.initial();
	while (scanf("%s", st) == 1 && st[0] != 'E') {
		int x, b, y, n;
		if (st[0] == 'S') {
			for (int i = 0; i < N; ++ i) {
				if (i) putchar(' ');
				printf("%d", ret[i]);
			}
			puts(""); memset(ret, 0, sizeof(ret));
		} else if (st[0] == 'A') {
			scanf("%d", &x);
			Access(x);
		} else if (st[0] == 'R') {
			scanf("%d%d%d", &b, &y, &n);
			for (int i = 0; i < n; ++ i) {
				Access(b + y * i);
			}
		}
	}
	return 0;
}
