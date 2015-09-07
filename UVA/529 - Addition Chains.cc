#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 10000 + 10;

int A[MAXN], N, ret;

bool dfs(int dep) {
	if (dep >= ret) return (A[dep - 1] == N);
	for (int i = 0; i < dep; ++ i)
		for (int j = i; j < dep; ++ j)
			if (A[i] + A[j] > A[dep - 1] && A[i] + A[j] <= N) {
				int s = A[i] + A[j]; A[dep] = s;
				for (int k = dep; k < ret; ++ k) s <<= 1;
				if (s >= N && dfs(dep + 1)) return true;
			}
	return false;
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		ret = 0; A[0] = 1;
		for (int i = 1; i < N; i <<= 1, ret ++);
		while (1) {
			ret ++;
			if (dfs(1)) break;
		}
		for (int i = 0; i < ret; ++ i) {
			if (i) putchar(' ');
			printf("%d", A[i]);
		}
		puts("");
	}
	return 0;
}
