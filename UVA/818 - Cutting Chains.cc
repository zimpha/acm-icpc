#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 20;

int g[MAXN][MAXN], vis[MAXN], n, m;

bool two(int mask) {
	for (int i = 0; i < n; ++ i) {
		if (mask & (1 << i)) continue;
		int deg = 0;
		for (int j = 0; j < n; ++ j) {
			if (mask & (1 << j)) continue;
			if (g[i][j]) deg ++;
		}
		if (deg > 2) return true;
	}
	return false;
}

bool dfs(int mask, int u, int f) {
	vis[u] = true;
	for (int i = 0; i < n; ++ i) {
		if (!g[u][i] || (mask & (1 << i)) || i == f) continue;
		if (vis[i] || dfs(mask, i, u)) return true;
	}
	return false;
}

bool circle(int mask) {
	m = 0; memset(vis, 0, sizeof(vis));
	for (int i  = 0; i < n; ++ i) {
		if (vis[i] || (mask & (1 << i))) continue;
		m ++;
		if (dfs(mask, i, -1)) return true;
	}
	return false;
}

int popcount(int s) {
	return (s == 0) ? 0 : popcount(s >> 1) + (s & 1);
}

int main() {
	int cas = 0;
	while (scanf("%d", &n) == 1 && n) {
		memset(g, 0, sizeof(g));
		for (int a, b; scanf("%d%d", &a, &b) == 2 && a != -1; ) {
			g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
		}
		int ret = 1e9;
		for (int mask = 0; mask < (1 << n) - 1; ++ mask) {
			if (two(mask) || circle(mask)) continue;
			if (popcount(mask) >= m - 1) ret = min(ret, popcount(mask));
		}
		printf("Set %d: Minimum links to open is %d\n", ++ cas, ret);
	}
	return 0;
}
