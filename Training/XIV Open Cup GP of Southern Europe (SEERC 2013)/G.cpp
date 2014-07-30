#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;

int dp[MAXN][5], a[MAXN], b[MAXN], c[MAXN];
int N;

int main() {
	freopen("g.in", "r", stdin);
	scanf("%d", &N);
	for (int i = 1; i <= N; ++ i) scanf("%d%d%d", a + i, b + i, c + i);
	dp[1][0] = a[1]; dp[1][1] = 0; dp[1][2] = b[1]; dp[1][3] = 0; dp[1][4] = 0;
	for (int i = 2; i <= N; ++ i) {
		dp[i][0] = dp[i - 1][4] + a[i];
		dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + b[i];
		if (i != N) {
			dp[i][2] = dp[i - 1][4] + b[i];
			dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]) + c[i];
		}
		dp[i][4] = max(dp[i - 1][0], dp[i - 1][1]);
	}
	printf("%d\n", max(dp[N][0], max(dp[N][1], dp[N][4])));
	fclose(stdin);
	return 0;
}
