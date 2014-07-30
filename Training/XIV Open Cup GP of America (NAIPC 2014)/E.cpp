#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN = 210, MOD = 1000000007;

vector<int> G[MAXN];
int size[MAXN], dp[MAXN][MAXN][2], C[MAXN][MAXN];
int N, K;

void prepare() {
	for (int i = 0; i < MAXN; ++ i) {
		C[i][i] = C[i][0] = 1;
		for (int j = 1; j < i; ++ j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			if (C[i][j] >= MOD) C[i][j] -= MOD;
		}
	}
}

void dfs(int u) {
	size[u] = 1;
	for (auto v : G[u]) {
		dfs(v);
		size[u] += size[v];
	}
}

void calc(int u, int e) {
	int cnt[MAXN], s = size[u] - 1, fs = size[G[u][0]] - e;
	for (int i = 0; i <= K - e; ++ i) {
		cnt[i] = (LL)dp[G[u][0]][i][0] * C[s][fs] % MOD;
		if (!e) {
			cnt[i] += (LL)dp[G[u][0]][i][1] * C[s][fs] % MOD;
			if (cnt[i] >= MOD) cnt[i] -= MOD;
		}
	}
	s -= size[G[u][0]];
	for (int i = 1; i < (int)G[u].size(); ++ i) {
		int tmp[MAXN], v = G[u][i]; memset(tmp, 0, sizeof(tmp));
		for (int j1 = 0; j1 <= K - e; ++ j1) {
			for (int j2 = 0; j1 + j2 <= K - e; ++ j2) {
				int j = j1 + j2;
				tmp[j] += (LL)cnt[j1] * dp[v][j2][0] % MOD * C[s][size[v]] % MOD;
				if (tmp[j] >= MOD) tmp[j] -= MOD;
				tmp[j] += (LL)cnt[j1] * dp[v][j2][1] % MOD * C[s][size[v]] % MOD;
				if (tmp[j] >= MOD) tmp[j] -= MOD;
			}
		}
		s -= size[v];
		for (int j = 0; j <= K - e; ++ j) cnt[j] = tmp[j];
	}
	for (int i = 0; i <= K - e; ++ i) {
		dp[u][i + e][e] += cnt[i];
		if (dp[u][i + e][e] >= MOD) dp[u][i + e][e] -= MOD;
	}
}

void solve(int u, int e) {
	if (dp[u][0][e] != -1) return;
	for (int i = 0; i <= K; ++ i) dp[u][i][e] = 0;
	if (!G[u].size()) {
		dp[u][0][0] = 1;
		return;
	}
	for (auto v : G[u]) {
		solve(v, 0);
		solve(v, 1);
	}
	if (e) {
		if (K == 0) return;
		for (int i = 0; i < (int)G[u].size(); ++ i) {
			swap(G[u][0], G[u][i]);
			calc(u, e);
			swap(G[u][0], G[u][i]);
		}
	}
	else calc(u, e);
}

int main() {
	prepare();
	while (scanf("%d%d", &N, &K) == 2 && N) {
		for (int i = 0; i < N; ++ i) G[i].clear();
		for (int i = 1; i < N; ++ i) {
			int x; scanf("%d", &x); x --;
			G[x].push_back(i);
		}
		dfs(0);
		memset(dp, -1, sizeof(dp));
		solve(0, 0);
		solve(0, 1);
		int ret = 0;
		for (int i = 0; i <= K; ++ i) {
			ret += dp[0][i][0];
			if (ret >= MOD) ret -= MOD;
			ret += dp[0][i][1];
			if (ret >= MOD) ret -= MOD;
		}
		printf("%d\n", ret);
	} 
	return 0;
}
