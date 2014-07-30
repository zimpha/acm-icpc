#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 510;

double dp[MAXN], S[MAXN];
double C[MAXN];
double P[MAXN];
int N, K;

int main() {
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= K; ++ i) scanf("%lf", P + i);
		memset(dp, 0, sizeof(dp));
		memset(C, 0, sizeof(C));
		memset(S, 0, sizeof(S));
		for (int i = 1, Q; i <= N; ++ i) {
			scanf("%d", &Q);
			while (Q --) {
				double x, c; scanf("%lf%lf", &c, &x);
				C[i] += x * c;
			}
		}
		dp[1] = C[1];
		S[1] = 1;
		for (int i = 1; i < N; ++ i) {
			for (int j = 1; j <= K; ++ j) {
				S[i + j] += S[i] * P[j];
				dp[i + j] += P[j] * dp[i] + C[i + j] * S[i] * P[j];
			}
		}
		for (int i = N + 1; i <= N + K; ++ i) dp[N] += dp[i];
		printf("Case #%d: %.6f\n", cas, dp[N]);
	}
	return 0;
}
