#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAXN = 500 + 10;
const int MAXL = 250000 + 10;

typedef long long LL;

int A[MAXN][MAXN], N, M, L;
int x[MAXL], y[MAXL];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++ i)
		for (int j = 0; j < M; ++ j)
			scanf("%d", &A[i][j]);
	scanf("%d", &L);
	for (int i = 0; i < L; ++ i) {
		scanf("%d%d", &x[i], &y[i]);
		x[i] --; y[i] --;
	}
	LL E1 = 0, E2 = 0;
	LL f1 = 0, f2 = 0;
	for (int i = 0; i < L; ++ i) {
		if (x[i] < N && y[i] < M) E1 += A[x[i]][y[i]];
		else f1 = -1;
		if (y[i] < N && x[i] < M) E2 += A[y[i]][x[i]];
		else f2 = -1;
	}
	if (f1 == -1) E1 = -1;
	if (f2 == -1) E2 = -1;
	if (E1 > E2) printf("%lld\n", E1);
	else printf("%lld\n", E2);
	return 0;
}
