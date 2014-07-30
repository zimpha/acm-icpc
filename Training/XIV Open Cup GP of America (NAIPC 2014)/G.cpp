#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40, inf = 1e9;

int dis[MAXN], level[MAXN], N, M, best;
int gold[MAXN], vis[MAXN];
vector<int> G[MAXN];

struct compare {
	bool operator() (const int &x, const int &y) const {
		if (dis[x] == dis[y]) return x > y;
		else return dis[x] > dis[y];
	}
};

void bfs() {
	fill(level, level + N, -1);
	queue<int> Q; Q.push(level[0] = 0);
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		for (auto v : G[u]) {
			if (level[v] == -1) {
				level[v] = level[u] + 1;
				Q.push(v);
			}
		}
	}
}

void spfa() {
	bool inque[MAXN];
	queue<int> Q;
	fill(inque, inque + N, 0);
	fill(dis, dis + N, inf);
	Q.push(dis[0] = 0); inque[0] = true;
	while (!Q.empty()) {
		int u = Q.front(); Q.pop();
		inque[u] = false;
		for (auto v : G[u]) {
			int cost = dis[u] + (vis[v] ? gold[v] : 0);
			if (dis[v] > cost) {
				dis[v] = cost;
				if (!inque[v]) Q.push(v), inque[v] = true;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < N; ++ i) ret += vis[i] ? gold[i] : 0;
	best = max(best, ret - dis[1]);
}

void dfs(int u) {
	vis[u] = true;
	for (auto v : G[u]) {
		if (v == 1) spfa();
		else if (!vis[v] && level[v] == level[u] + 1 && level[v] < level[1]) dfs(v);
	}
	vis[u] = false;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 2; i < N; ++ i) scanf("%d", &gold[i]);
		for (int i = 0; i < N; ++ i) G[i].clear();
		for (int i = 0; i < M; ++ i) {
			int x, y; scanf("%d%d", &x, &y);
			-- x, -- y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		best = 0;
		bfs();
		dfs(0);
		printf("%d\n", best);
	}
	return 0;
}
