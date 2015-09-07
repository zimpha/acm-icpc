#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 100;
typedef int matrix[60][60];

int X[MAXN];
int N, K, D;

void mul(matrix A, matrix B) {
	matrix C;
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < N; ++ j) {
			C[i][j] = 0;
			for (int k = 0; k < N; ++ k) {
				C[i][j] += A[i][k] * B[k][j];
				C[i][j] %= N;
			}
		}
	}
	memcpy(A, C, sizeof(C));
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &N, &K, &D);
		matrix A;
		memset(A, 0, sizeof(A));
		for (int i = 0; i < N; ++ i) {
			scanf("%d", &X[i]);
			for (int j = 1; j <= D; ++ j) {
				A[i][(i + j) % N] = 1;
				A[i][(i - j + N) % N] = 1;
			}
			A[i][i] = 0;
		}
		for (; K; K >>= 1) {
			if (K & 1) {
				int tmp[MAXN];
				for (int i = 0; i < N; ++ i) {
					tmp[i] = 0;
					for (int j = 0; j < N; ++ j) {
						tmp[i] += A[i][j] * X[j];
						tmp[i] %= N;
					}
				}
				for (int i = 0; i < N; ++ i) X[i] = tmp[i];
			}
			mul(A, A);
		}
		int mx = N;
		for (int i = 0; i < N; ++ i) mx = min(mx, X[i]);
		printf("%d\n", mx);
		for (int i = 0, f = 0; i < N; ++ i) {
			if (X[i] == mx) {
				if (f) putchar(' ' );
				else f = 1;
				printf("%d", i + 1);
			}
		}
		puts("");
	}
}
