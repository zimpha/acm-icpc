#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

typedef pair<int, int> PII;
vector<PII> G[MAXN], Gr[MAXN];

bool vis[MAXN], fuel[MAXN];
int f[MAXN], g[MAXN];
int N, M, C, P;

void spfa1() {
	queue<int> que;
	while (!que.empty()) que.pop();
	memset(vis, 0, sizeof(vis));
	memset(f, -1, sizeof(f));
	f[1] = C;
	vis[1] = true;
	que.push(1);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = 0; i < (int) G[u].size(); i++) {
			int v = G[u][i].first;
			int w = G[u][i].second;
			if (f[u] < w)continue;
			if (fuel[v]) {
				if (f[v] < C) {
					f[v] = C;
					if (!vis[v]) {
						vis[v] = true;
						que.push(v);
					}
				}
			}
			else {
				if (f[v] < f[u] - w) {
					f[v] = f[u] - w;
					if (!vis[v]) {
						vis[v] = true;
						que.push(v);
					}
				}
			}
		}
	}
}

void spfa2() {
	queue<int> que;
	while (!que.empty()) que.pop();
	memset(vis, 0, sizeof(vis));
	memset(g, 62, sizeof(g));
	g[N] = 0;
	vis[N] = true;
	que.push(N);
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		vis[u] = false;
		for (int i = 0; i < (int) Gr[u].size(); i++) {
			int v = Gr[u][i].first;
			int w = Gr[u][i].second;
			if (g[u] + w > C)continue;
			if (fuel[v]) {
				if (g[v] > 0) {
					g[v] = 0;
					if (!vis[v]) {
						vis[v] = true;
						que.push(v);
					}
				}
			}
			else {
				if (g[v] > g[u] + w) {
					g[v] = g[u] + w;
					if (!vis[v]) {
						vis[v] = true;
						que.push(v);
					}
				}
			}
		}
	}
}

int main() {
	while (scanf("%d%d%d", &N, &M, &C) == 3) {
		for (int i = 0; i <= N; i++) {
			G[i].clear();
			Gr[i].clear();
		}
		while (M--) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(make_pair(v, w));
			Gr[v].push_back(make_pair(u, w));
		}
		scanf("%d", &P);
		memset(fuel, 0, sizeof(fuel));
		for (int x, i = 0; i < P; i++) {
			scanf("%d", &x);
			fuel[x] = true;
		}
		spfa1();
		spfa2();
		scanf("%d", &P);
		int ret = 0;
		for (int q, v, i = 0; i < P; i++) {
			scanf("%d%d", &q, &v);
			if (g[q] <= C &&f[q] >= 0) {
				if (fuel[q])ret = max(ret, v * C);
				else ret = max(ret, v * (f[q] - g[q]));
			}
		}
		if (f[N] == -1) puts("-1");
		else printf("%d\n", ret);
	}
	return 0;
}

