#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 1000 + 10;

int A[MAXN], N, M;;

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		int ret = 0;
		M = 0;
		for (int i = 2; ; ++ i) {
			A[M] = i; ret += i;
			if (ret > N) break;
			M ++;
		}
		ret -= A[M]; N -= ret;
		for (int i = 0; i < M; ++ i) A[i] += N / M;
		N %= M;
		for (int i = M - 1; N; -- i, -- N) A[i] ++;
		for (int i = 0; i < M; ++ i) {
			if (i) putchar(' ');
			printf("%d", A[i]);
		}
		puts("");
		if (T) puts("");
	}
	return 0;
}
