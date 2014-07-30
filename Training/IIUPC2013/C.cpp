#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 16;
const int inf = 1e9;

struct Node {
	int v, w, id;
	Node() {}
	Node(int v, int w, int id) : v(v), w(w), id(id) {}
};

double dp[1 << MAXN];
double av[MAXN][MAXN];
int se[MAXN][MAXN];
vector<Node> G[MAXN];
int N, now;

void dfs(int u, int f, int l, int mask, int sum) {
	if (now != u) {
		se[now][u] = mask;
		av[now][u] = (double)sum / l;
	}
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		int v = G[u][i].v, w = G[u][i].w, p = G[u][i].id;
		if (v == f) continue;
		dfs(v, u, l + 1, mask | (1 << p), sum + w);
	}
}

int main() {
	while (scanf("%d", &N) == 1 && N) {
		for (int i = 0; i < N; ++ i) G[i].clear();
		for (int i = 0; i < N - 1; ++ i) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(Node(v, w, i));
			G[v].push_back(Node(u, w, i));
		}	
		for (int i = 0; i < N; ++ i) {
			now = i;
			dfs(i, -1, 0, 0, 0);
		}
		int S = 1 << (N - 1); dp[0] = 0;
		for (int mask = 1; mask < S; ++ mask) dp[mask] = inf;
		for (int mask = 0; mask < S; ++ mask) {
			if (dp[mask] == inf) continue;
			for (int i = 0; i < N; ++ i)
				for (int j = i + 1; j < N; ++ j) {
					if (mask & se[i][j]) continue;
					double &ret = dp[mask | se[i][j]];
					if (ret > dp[mask] + av[i][j]) {
						ret = dp[mask] + av[i][j];
					}
				}
		}
		printf("%.4f\n", dp[S - 1]);
	}
}
