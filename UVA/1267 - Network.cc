#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;

vector<int> G[MAXN], D[MAXN];
bool covered[MAXN];
int N, S, K, fa[MAXN];

void dfs(int u, int f, int d) {
	fa[u] = f;
	if (G[u].size() == (size_t)1 && d > K) D[d].push_back(u);
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		if (G[u][i] != f) dfs(G[u][i], u, d + 1);
	}
}

void dfs2(int u, int f, int d) {
	covered[u] = true;
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		if (G[u][i] != f && d < K) dfs2(G[u][i], u, d + 1);
	}
}

int solve() {
	int ret = 0;
	memset(covered, 0, sizeof(covered));
	for (int d = N - 1; d > K; -- d) {
		for (int i = 0; i < (int)D[d].size(); ++ i) {
			int u = D[d][i], v = u;
			if (covered[u]) continue;
			for (int j = 0; j < K; ++ j) v = fa[v];
			dfs2(v, -1, 0);
			ret ++;
		}
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &N, &S, &K);
		for (int i = 0; i < N; ++ i) G[i].clear(), D[i].clear();
		for (int i = 1; i < N; ++ i) {
			int a, b; scanf("%d%d", &a, &b); a --, b --;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(S - 1, -1, 0);
		printf("%d\n", solve());
	}
	return 0;
}
