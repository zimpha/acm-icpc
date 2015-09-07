#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
const int SIZE = 10000 + 10;

int cnt[SIZE], A[MAXN], B[SIZE];

int solve(int l, int r) {
	if (r - l + 1 > 10000) return 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = l; i <= r; ++ i) cnt[A[i]] ++;
	int m = 0;
	for (int i = 1; i < SIZE; ++ i) {
		while (cnt[i] --) {
			B[m ++] = i;
		}
	}
	int ret = SIZE;
	for (int i = 1; i < m; ++ i)
		ret = min(ret, abs(B[i] - B[i - 1]));
	return ret;
}

int main() {
	int T, N; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 1; i <= N; ++ i) scanf("%d", &A[i]);
		scanf("%d", &N);
		while (N --) {
			int l, r; scanf("%d%d", &l, &r);
			printf("%d\n", solve(l, r));
		}
	}
	return 0;
}
