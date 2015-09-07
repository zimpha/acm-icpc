#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL inf = 27179869184000ll;
const int SIZE = 30;

LL S[SIZE][SIZE][SIZE];

inline LL get_sum(int x, int y1, int y2, int z1, int z2) {
	return S[x][y2][z2] + S[x][y1 - 1][z1 - 1] - S[x][y1 - 1][z2] - S[x][y2][z1 - 1];
}

inline LL solve(int n, int y1, int y2, int z1, int z2) {
	LL A[SIZE], ret = -inf, sum = 0;
	for (int i = 1; i <= n; ++ i) {
		A[i] = get_sum(i, y1, y2, z1, z2);
		sum = (sum > 0 ? sum : 0) + A[i];
		ret = max(ret, sum);
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		int A, B, C; scanf("%d%d%d", &A, &B, &C);
		memset(S, 0, sizeof(S));
		for (int i = 1; i <= A; ++ i) {
			for (int j = 1; j <= B; ++ j) {
				for (int k = 1; k <= C; ++ k) {
					scanf("%lld", &S[i][j][k]);
				}
			}
		}
		for (int i = 1; i <= A; ++ i) {
			for (int j = 1; j <= B; ++ j) {
				for (int k = 1; k <= C; ++ k) {
					S[i][j][k] += S[i][j - 1][k] + S[i][j][k - 1] - S[i][j - 1][k - 1];
				}
			}
		}
		LL ret = -inf;
		for (int y1 = 1; y1 <= B; ++ y1) {
			for (int y2 = y1; y2 <= B; ++ y2) {
				for (int z1 = 1; z1 <= C; ++ z1) {
					for (int z2 = z1; z2 <= C; ++ z2) {
						LL tmp = solve(A, y1, y2, z1, z2);
						ret = max(ret, tmp);
					}
				}
			}
		}
		printf("%lld\n", ret);
		if (T) puts("");
	}
	return 0;
}
