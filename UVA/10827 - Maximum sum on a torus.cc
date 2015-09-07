#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200;
const int inf = 1e9;

int A[MAXN][MAXN], S[MAXN];
int N;

inline int solve(int S[], int N, int M) {
	static int Q[MAXN];
	int head = 0, tail = 0, ret = -inf;
	Q[0] = 0;
	for (int i = 1; i <= N; ++ i) {
		while (head <= tail && Q[head] < i - M) head ++;
		ret = max(ret, S[i] - S[Q[head]]);
		while (head <= tail && S[i] <= S[Q[tail]]) tail --;
		Q[++ tail] = i;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d", &N);
		memset(A, 0, sizeof(A));
		for (int i = 1; i <= N; ++ i) {
			for (int j = 1; j <= N; ++ j) {
				scanf("%d", &A[i][j]);
				A[i + N][j + N] = A[i][j];
				A[i + N][j] = A[i][j];
				A[i][j + N] = A[i][j];
			}
		}
		for (int i = 1; i <= 2 * N; ++ i) {
			for (int j = 1; j <= 2 * N; ++ j) {
				A[i][j] += A[i - 1][j];
			}
		}
		int ret = -inf;
		for (int r1 = 1; r1 <= 2 * N; ++ r1) {
			for (int r2 = r1; r2 <= 2 * N && r2 < r1 + N; ++ r2) {
				S[0] = 0;
				for (int i = 1; i <= 2 * N; ++ i) {
					S[i] = S[i - 1] + A[r2][i] - A[r1 - 1][i];
				}
				int tmp = solve(S, 2 * N, N);
				if (tmp > ret) ret = tmp;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
