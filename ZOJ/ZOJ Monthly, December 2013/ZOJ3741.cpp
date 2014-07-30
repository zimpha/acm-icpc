#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=105;
const int MAXL=10;

int dp[MAXN][MAXN], A[MAXN];
int sum[MAXN][MAXN][MAXL];
int N, L, X, Y;

int main() {
	while (scanf("%d%d%d%d", &L, &N, &X, &Y) == 4) {
		for (int i = 1; i <= N; ++ i) scanf("%d", &A[i]);
		memset(sum, 0, sizeof(sum));
		for (int k = 0; k <= 6; ++ k)
			for (int i = 1; i <= N; ++ i)
				for (int j = i; j <= N; ++ j) {
					sum[i][j][k] = sum[i][j - 1][k] + (A[j] <= k);
				}
		memset(dp, 0, sizeof(dp));
		int L1 = (L == 5) ? L : L + 1;
		for (int i = 1; i <= N; ++ i) {
			dp[i][0] = dp[i - 1][0] + sum[i][i][L];
			for (int j = 1; j <= i; ++ j) {
				int upp = max(0, j - X - Y);
				for (int k = 0; k <= upp; ++ k) {
					if (i >= j && i <= j + X - 1) 
						dp[i][j] = max(dp[i][j], dp[j - 1][k] + sum[j][i][L1]);
					if (i >= j + X && i <= j + X + Y - 1) 
						dp[i][j] = max(dp[i][j], dp[j - 1][k] + sum[j][j + X - 1][L1] + sum[j + X][i][0]);
					if (i >= j + X + Y) 
						dp[i][j] = max(dp[i][j], dp[j - 1][k] + sum[j][j + X - 1][L1] + sum[j + X][j + X + Y - 1][0] + sum[j + X + Y][i][L]);
				}
			}
		}
		int ret = 0;
		for (int i = 0; i <= N; ++ i) ret = max(ret, dp[N][i]);
		printf("%d\n", ret);
	}
	return 0;
}
