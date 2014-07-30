#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[1 << 20];
int dp[1 << 20];
int f[20];

int main() {
	for (int i = 1; i < (1 << 20); ++ i) cnt[i] = cnt[i >> 1] + (i & 1);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		int N, M, K; scanf("%d%d%d", &N, &M, &K);
		for (int i = 0; i < N; ++ i) f[i] = 0;
		for (int i = 0; i < M; ++ i) {
			int x, y; scanf("%d%d", &x, &y); x --, y --;
			f[x] |= (1 << y);
			f[y] |= (1 << x);
		}
		queue<int> Q;
		while (!Q.empty()) Q.pop();
		Q.push(f[0]); dp[f[0]] = cas;
		while (!Q.empty()) {
			int now = Q.front(); Q.pop();
			for (int i = 0; i < N; ++ i) {
				if ((now >> i) & 1) continue;
				int next = now | (1 << i);
				if (cnt[f[i] & now] >= K && dp[next] != cas) {
					Q.push(next);
					dp[next] = cas;
				}
			}
		}
		int ret = N + 1;
		for (int i = 0; i < (1 << N); ++ i) {
			if (dp[i] != cas) continue;
			if (i >> (N - 1)) ret = min(ret, cnt[i] - cnt[f[0]] - 1);
		}
		if (ret > N) ret = -1;
		else if (ret < 0) ret = 0;
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}
