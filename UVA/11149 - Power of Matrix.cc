#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 50;

struct Matrix {
	int a[MAXN][MAXN], n;
	
	void clear() {
		n = 0;
		memset(a, 0, sizeof(a));
	}

	Matrix operator + (const Matrix &b) const {
		Matrix tmp; tmp.n = n;
		for (int i = 0; i < n; ++ i)
			for (int j = 0; j < n; ++ j)
				tmp.a[i][j] = (a[i][j] + b.a[i][j]) % 10;
		return tmp;
	}

	Matrix operator * (const Matrix &b) const {
		Matrix S; S.clear(); S.n = n;
		for (int i = 0; i < n; ++ i) {
			for (int j = 0; j < n; ++ j) {
				for (int k = 0; k < n; ++ k)
					S.a[i][j] = (S.a[i][j] + a[i][k] * b.a[k][j]) % 10;
			}
		}
		return S;
	}
};

Matrix A, E;
int N, K;

inline Matrix power(Matrix A, int K) {
	Matrix ret = E;
	for (; K; K >>= 1) {
		if (K & 1) ret = ret * A;
		A = A * A;
	}
	return ret;
}

Matrix solve(Matrix A, int K) {
	if (K == 1) return A;
	Matrix B = solve(A, K >> 1);
	Matrix S = (B * power(A, K >> 1)) + B;
	if (K & 1) S = S + power(A, K);
	return S;
}

int main() {
	while (scanf("%d%d", &N, &K) == 2 && N) {
		E.clear(); A.n = E.n = N;
		for (int i = 0; i < N; ++ i) {
			E.a[i][i] = 1;
			for (int j = 0; j < N; ++ j) {
				scanf("%d", &A.a[i][j]);
				A.a[i][j] %= 10;
			}
		}
		A = solve(A, K);
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < N; ++ j) {
				if (j) putchar(' ');
				printf("%d", A.a[i][j]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
