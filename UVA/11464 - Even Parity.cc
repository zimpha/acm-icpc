#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 20;
const int INF = 1e9;

int A[MAXN][MAXN];
int N;

int solve(int mask) {
	int B[MAXN][MAXN], ret = 0;
	memcpy(B, A, sizeof(A));
	for (int i = 0; i < N; ++ i) {
		if ((mask >> i) & 1) {
			if (B[1][i + 1] == 1) return INF;
			B[1][i + 1] ^= 1, ret ++;
		}
	}
	for (int i = 2; i <= N; ++ i) {
		for (int j = 1; j <= N; ++ j) {
			int t = B[i][j] ^ B[i - 1][j - 1] ^ B[i - 1][j + 1] ^ B[i - 2][j];
			if (t) {
				if (B[i][j] == 1) return INF;
				B[i][j] ^= 1, ret ++;
			}
		}
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d", &N);
		memset(A, 0, sizeof(A));
		for (int i = 1; i <= N; ++ i)
			for (int j = 1; j <= N; ++ j)
				scanf("%d", &A[i][j]);
		int ret = INF;
		for (int mask = 0; mask < (1 << N); ++ mask) {
			int tmp = solve(mask);
			if (tmp < ret) ret = tmp;
		}
		if (ret == INF) ret = -1;
		printf("Case %d: %d\n", cas, ret);
	}
	return 0;
}
