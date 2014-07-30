#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200;

vector<int> G[MAXN];
int dis[MAXN], col[MAXN], vis[MAXN];
int N, M;

int spfa(int u) {
	for (int i = 1; i <= N; ++ i) dis[i] = N, vis[i] = 0;
	queue<int> Q;
	Q.push(u); vis[u] = true; dis[u] = 0;
	while (!Q.empty()) {
		u = Q.front(); Q.pop(); vis[u] = 0;
		for (int i = 0; i < (int)G[u].size(); ++ i) {
			int v = G[u][i], w = (col[u] != col[v]);
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) vis[v] = true, Q.push(v);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; ++ i) ret = max(ret, dis[i]);
	return ret;
}

int main() {
	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (int i = 1; i <= N; ++ i) {
			scanf("%d", col + i);
			G[i].clear();
		}
		while (M --) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v); G[v].push_back(u);
		}
		int ret = N;
		for (int i = 1; i <= N; ++ i) {
			int now = spfa(i);
			ret = min(ret, now);
		}
		printf("%d\n", ret);
	}
	return 0;
}
