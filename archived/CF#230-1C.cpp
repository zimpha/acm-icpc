#include <cstring>
#include <iostream>
using namespace std;

typedef long long LL;
const int MAXN = 100;
const int MOD = 1e9 + 7;

typedef int matrix[MAXN][MAXN];

int C[MAXN][MAXN], k, m;
LL n;

void mul(matrix A, matrix B) {
	matrix C;
	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < m; ++ j) {
			C[i][j] = 0;
			for (int k = 0; k < m; ++ k) {
				C[i][j] += (LL)A[i][k] * B[k][j] % MOD;
				C[i][j] %= MOD;
			}
		}
	}
	memcpy(A, C, sizeof(C));
}

int main() {
	cin >> n >> k;
	for (int i = 0; i <= k; ++ i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++ j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			C[i][j] %= MOD;
		}
	}
	matrix A, ret; m = 2 * k + 3;
	for (int i = 0; i < m; ++ i)
		for (int j = 0; j < m; ++ j)
			ret[i][j] = A[i][j] = (i == j);
	for (int j = 1; j < k + 2; ++ j) A[0][j] = A[0][j + k + 1] = C[k][j - 1];
	for (int i = 1; i < k + 2; ++ i) {
		for (int j = i; j < k + 2; ++ j) {
			A[i][j] = A[i][j + k + 1] = C[k - i + 1][k - j + 1];
		}
	}
	for (int i = k + 2; i < m; ++ i) {
		A[i][i] = 0;
		for (int j = 0; j < k + 2; ++ j) {
			A[i][j] = A[i - k - 1][j];
		}
	}

	n --;
	for (; n; n >>= 1) {
		if (n & 1) mul(ret, A);
		mul(A, A);
	}
	int sum = 0;
	for (int i = 0; i < m; ++ i) sum = (sum + ret[0][i]) % MOD;
	cout << sum << endl;
	return 0;
}
