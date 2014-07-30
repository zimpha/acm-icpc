#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;
const int inf = 1e9;

struct Edge {
	int v, w;
	Edge() {}
	Edge(int a, int b) : v(a), w(b) {}
};

vector<Edge> G[MAXN];
int dis[MAXN], vis[MAXN];
int N, M, ret;

void spfa(int s) {
	queue<int> Q;
	for (int i = 0; i < N; ++ i) dis[i] = inf, vis[i] = 0;
	Q.push(s); dis[s] = 0; vis[s] = 1;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop(); vis[u] = 0;
		for (int i = 0; i < (int)G[u].size(); ++ i) {
			int v = G[u][i].v, w = G[u][i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) {
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

void dfs(int u, int sum) {
	vis[u] = 1; ret ++;
	int mx = inf;
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		if (!vis[G[u][i].v] && mx > G[u][i].w) {
			mx = G[u][i].w;
		}
	}
	for (int i = 0; i < (int)G[u].size(); ++ i) {
		if (!vis[G[u][i].v] && G[u][i].w == mx) {
			if (sum + mx == dis[G[u][i].v]) {
				dfs(G[u][i].v, sum + mx);
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++ i) G[i].clear();
	for (int i = 0; i < M; ++ i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w); u --, v --;
		G[u].push_back(Edge(v, w));
	}
	ret = 0;
	for (int i = 0; i < N; ++ i) {
		spfa(i);
		memset(vis, 0, sizeof(vis));
		dfs(i, 0);
		for (int j = 0; j < N; ++ j) ret += (!vis[j] && dis[j] >= inf);
	}
	printf("%d\n", ret);
	return 0;
}
