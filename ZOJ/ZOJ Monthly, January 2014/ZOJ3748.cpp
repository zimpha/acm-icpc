#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=205;
const int inf=100000000;

vector<int> edge[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][MAXN][2];
int g[MAXN][2];
int ret[MAXN];
int fa[MAXN];
int N, M;

void update(int &a, int b) {if (a==-1 || a > b) a = b;}

void dfs(int u) {
	for (int i = 0; i < (int)edge[u].size(); ++ i) dfs(edge[u][i]);
	if (edge[u].empty()) {
		dp[u][0][0] = a[u];
		dp[u][0][1] = b[u];
		dp[u][1][1] = dp[u][1][0] = c[u];
	}
	else {
		memset(g, -1, sizeof(g));
		g[0][0] = g[0][1] = 0;
		for (int i = 0; i < (int)edge[u].size(); ++ i) {
			int v = edge[u][i];
			for (int j = M; j >= 0; -- j) {
				int tmp0 = -1, tmp1 = -1;
				for (int k = 0; k <= j; ++ k) {
					if (g[j - k][0] != -1 && dp[v][k][0] != -1) update(tmp0, g[j - k][0] + dp[v][k][0]);
					if (g[j - k][1] != -1 && dp[v][k][1] != -1) update(tmp1, g[j - k][1] + dp[v][k][1]);
				}
				g[j][0] = tmp0; g[j][1] = tmp1;
			}
		}
		for (int j = 0; j <= M; ++ j) {
			if (j < M) {
				if (g[j][1] != -1) update(dp[u][j + 1][0], g[j][1] + c[u]);
				if (g[j][1] != -1) update(dp[u][j + 1][1], g[j][1] + c[u]);
			}
			if (g[j][0] != -1) update(dp[u][j][0], g[j][0] + a[u]);
			if (g[j][1] != -1) update(dp[u][j][1], g[j][1] + b[u]);
		}
	}
}

int main() {
	int tests;
	scanf("%d", &tests);
	while (tests--) {
		memset(dp, -1, sizeof(dp));
		scanf("%d%d", &N, &M);
		for (int i = 0; i <= N; ++ i) edge[i].clear();
		for (int i = 1; i <= N; ++ i) {
			scanf("%d%d%d%d", &fa[i], &a[i], &b[i], &c[i]);
			b[i] = min(b[i], a[i]);
			if (fa[i] != 0) edge[fa[i]].push_back(i);
		}
		for (int i = 1; i <= M; ++ i) ret[i]=inf; ret[0]=0;
		for (int i = 1; i <= N; ++ i) {
			if (fa[i]) continue;
			dfs(i);
			for (int j = M; j >= 0; -- j) {
				int tmp = -1;
				for (int k = 0; k <= j; ++ k)
					if (ret[j - k] != -1 && dp[i][k][0] != -1)
						update(tmp, ret[j - k] + dp[i][k][0]);
				ret[j] = tmp;
			}
		}
		int res = inf;
		for (int i = 0; i <= M; ++ i)
			if (ret[i] != -1) res = min(res, ret[i]);
		printf("%d\n", res);
	}
	return 0;
}
