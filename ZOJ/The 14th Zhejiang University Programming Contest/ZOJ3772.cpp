#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

typedef long long LL;
typedef int matrix[2][2];

const int MAXN = 100000 + 10;
const int MOD = 1e9 + 7;

matrix Tr[MAXN << 2];
int A[MAXN];

void init(matrix m, int x) {
	m[0][0] = 0; m[1][0] = x;
	m[0][1] = m[1][1] = 1;
}

void mul(matrix c, matrix a, matrix b) {
	for (int i = 0; i < 2; ++ i) 
		for (int j = 0; j < 2; ++ j) {
			LL tmp = 0;
			for (int k = 0; k < 2; ++ k) tmp += (LL)a[i][k] * b[k][j];
			c[i][j] = tmp % MOD;
		}
}

void build(int l, int r, int rt) {
	if (l + 1 == r) {
		scanf("%d", &A[l]);
		init(Tr[rt], A[l]);
		return ;
	}
	build(l, mid, lson); build(mid, r, rson);
	mul(Tr[rt], Tr[rson], Tr[lson]);
}

LL ret[2];

void Query(int l, int r, int L, int R, int rt) {
	if (L <= l && R >= r) {
		matrix &T = Tr[rt];
		LL tmp[2];
		tmp[0] = (T[0][0] * ret[0] + T[0][1] * ret[1]) % MOD;
		tmp[1] = (T[1][0] * ret[0] + T[1][1] * ret[1]) % MOD;
		ret[0] = tmp[0]; ret[1] = tmp[1];
		return;
	}
	if (L < mid) Query(l, mid, L, R, lson);
	if (R > mid) Query(mid, r, L, R, rson);
}

int main() {
	int T, N, M; scanf("%d", &T);
	while (T --) {
		scanf("%d%d", &N, &M);
		build(0, N, 1);
		while (M --) {
			int l, r; scanf("%d%d", &l, &r);
			if (l + 1 >= r) printf("%d\n", A[r - 1]);
			else {
				ret[0] = A[l - 1]; ret[1] = A[l];
				Query(0, N, l + 1, r, 1);
				printf("%d\n", (int)ret[1]);
			}
		}
	}
	return 0;
}
