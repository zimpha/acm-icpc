#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAXN = 10000 + 10;

bool C[MAXN];
int ret[MAXN][2];

void BinarySearch(int N, int L, int x) {
	int p = 0, q = N - 1, times = 0;
	while (p <= q) {
		int mid = (p + q) / 2;
		times ++;
		if (mid == x) {
			if (L == times) C[N] = 1;
			return;
		}
		if (x < mid) q = mid - 1;
		else p = mid + 1;
	}
}

int main() {
	int N, L;
	while (scanf("%d%d", &N, &L) == 2) {
		memset(C, 0, sizeof(C));
		for (int i = N; i < MAXN; ++ i) BinarySearch(i, L, N);
		int tot = 0;
		for (int i = 0, j; i <= 10000; i = j) {
			if (C[i]) {
				for (j = i; j <= 10000 && C[j]; ++ j);
				ret[tot][0] = i; ret[tot][1] = j - 1; tot ++;
			} else j = i + 1;
		}
		printf("%d\n", tot);
		for (int i = 0; i < tot; ++ i)
			printf("%d %d\n", ret[i][0], ret[i][1]);
	}
	return 0;
}
