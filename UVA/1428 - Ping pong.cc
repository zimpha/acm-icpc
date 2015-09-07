#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN = 20000 + 10;
const int MAXC = 100000 + 10;

int C[MAXC], A[MAXN], B[MAXN], D[MAXN];
int N;

void add(int idx) {
	for (int i = idx; i < MAXC; i += i & -i) {
		C[i] ++;
	}
}

int get(int idx) {
	int ret = 0;
	for (int i = idx; i > 0; i -= i & -i) {
		ret += C[i];
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &A[i]);
		}
		memset(C, 0, sizeof(C));
		for (int i = 0; i < N; ++ i) {
			B[i] = get(A[i] - 1);
			add(A[i]);
		}
		memset(C, 0, sizeof(C));
		for (int i = N - 1; i >= 0; -- i) {
			D[i] = get(A[i] - 1);
			add(A[i]);
		}
		long long ret = 0;
		for (int i = 0; i < N; ++ i) {
			ret += B[i] * (N - i - 1 - D[i]) + D[i] * (i - B[i]);
		}
		printf("%lld\n", ret);
	}
	return 0;
}
